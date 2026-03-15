# A-Maze-ing Pac-Man – Project Plan & Structure

## **Project Objectives**
- Build a **modular 2D tile-based engine** for multiple games (Pac-Man, Bomberman, Sokoban…).
- Start with **Pac-Man** as the first fully functional game.
- Implement **modularity early** to:
  - Support multiple renderers (terminal, SDL rectangle/image, SDL pixel-level)
  - Support multiple games in the future
  - Allow cross-platform expansion
- Step-by-step development with **long-term goals in mind**.

---

## **Current Status**
| Feature | Old Version | New Version | Status |
|---------|------------|------------|--------|
| Maze generation | ✅ | ❌ | Needs rework |
| Maze history (visualization) | ✅ | ❌ | Needs integration |
| Map conversion | ✅ | ❌ | Needs rework |
| Map editing | ✅ | ❌ | Needs rework |
| SDL rendering (rectangle) | ✅ | ❌ | Needs full restore |
| SDL pixel renderer | ❌ | ❌ | Not implemented |
| Terminal renderer | Partial | ❌ | Not implemented |
| Sound support | ❌ | ❌ | Not implemented |
| Player movement | ❌ | ❌ | Not implemented |
| Enemy AI | ❌ | ❌ | Not implemented |
| Map file support | ❌ | ❌ | Not implemented |

---

## **Proposed Modular Structure**

### **1. Core Modules**
- **Engine**
  - Game loop (update, render, input handling)
  - Timing & frame control
  - Event handling abstraction (keyboard/controller)
  - State management (running, paused, game over)
  
- **Map**
  - Maze generation & storage
  - Map loading from file
  - 2D array or tile-based representation
  - Tile properties: wall, path, food, spawn points
  - Map history buffer for visualization/debugging
  
- **Renderer**
  - Base interface:
    - `renderTile(x, y, type)`
    - `renderMap(map)`
  - Terminal renderer
  - SDL rectangle/image renderer
  - SDL pixel-level renderer
  - Renderer selection at runtime
  - Render UI other than map (lives, score)
  - Render map
  
- **Sound**
  - Sound effects
  - Background music
  - Volume & mute control
  - SDL_mixer wrapper or equivalent

---

### **2. Game Modules (Pac-Man specific)**
- **Player**
  - Movement & collision detection
  - Lives & score
  - Optional animation frames
- **Enemies (Ghosts)**
  - Pathfinding (BFS / DFS / A* for maze)
  - Behavior modes: chase, scatter, frightened
- **Gameplay**
  - Pellet collection
  - Power-ups
  - Score system
  - Win / lose conditions

---

### **3. Utility Modules**
- Logger / debug output
- Config / settings (screen size, tile size, sound on/off)
- Input abstraction (keyboard, controller)
- Timer & FPS measurement

---

## **Phase-by-Phase Development Plan**

### **Phase 1 – Core Infrastructure**
1. Set up **modular engine structure** with base classes/interfaces.
2. Restore **maze generation & map conversion**.
3. Implement **terminal renderer** for debugging.
4. Integrate **map history visualization**.
5. Abstract map for both terminal and SDL renderers.

### **Phase 2 – SDL Renderers**
1. Restore **rectangle/image SDL renderer**.
2. Implement **pixel-level SDL renderer**.
3. Ensure both renderers can use the same map without duplication.

### **Phase 3 – Basic Gameplay**
1. Player movement & input handling
2. Wall collision detection
3. Pellet collection & scoring
4. Basic sound effects
5. Frame-independent movement for smooth gameplay

### **Phase 4 – Advanced Gameplay**
1. Enemy movement / AI
2. Power-ups & special items
3. Win / lose conditions
4. Animations

### **Phase 5 – Map File Support**
- Ability to load predefined maps for testing & expansion.

### **Phase 6 – Multi-Game Support**
- Abstract game rules to support multiple tile-based games.
- Add Sokoban or Bomberman as proof of concept.

---

## **Implementation Guidelines**
- Use **C++ classes and interfaces** for modularity.
- Keep **renderers decoupled** from game logic.
- Keep **map as abstract 2D grid**, renderer just interprets it.
- Keep **history buffer** for maze generation visual debug.
- SDL3 should **only handle rendering & sound**.
- Use **modern C++ features**: smart pointers, `std::vector` for maps, RAII for SDL resources.

---

## **Comments / Notes Section**
- Add notes here for **reordering phases** or adding new modules.
- Example: “Add multiplayer support” or “Introduce dynamic tile types”.

---

## **Proposed Folder & File Structure**
```
A-Maze-ing_Pac-Man/
│
├── include/
│ ├── engine/ # Core engine interfaces & base classes
│ │ ├── GameEngine.hpp
│ │ ├── GameState.hpp
│ │ └── Timer.hpp
│ │
│ ├── map/
│ │ ├── Map.hpp
│ │ ├── MazeGenerator.hpp
│ │ └── MapHistory.hpp # [TODO] placeholder
│ │
│ ├── renderer/
│ │ ├── Renderer.hpp # Base interface
│ │ ├── TerminalRenderer.hpp
│ │ ├── SDLRectRenderer.hpp
│ │ └── SDLPixelRenderer.hpp # [TODO] placeholder
│ │
│ ├── sound/
│ │ ├── SoundManager.hpp
│ │ └── MusicManager.hpp # [TODO] placeholder
│ │
│ ├── game/ # Pac-Man specific
│ │ ├── Player.hpp
│ │ ├── Enemy.hpp
│ │ └── Gameplay.hpp
│ │
│ └── utils/
│ ├── Logger.hpp
│ ├── Config.hpp
│ └── Input.hpp
│
├── src/
│ ├── engine/
│ │ ├── GameEngine.cpp
│ │ ├── GameState.cpp
│ │ └── Timer.cpp
│ │
│ ├── map/
│ │ ├── Map.cpp
│ │ ├── MazeGenerator.cpp
│ │ └── MapHistory.cpp # [TODO] placeholder
│ │
│ ├── renderer/
│ │ ├── TerminalRenderer.cpp
│ │ ├── SDLRectRenderer.cpp
│ │ └── SDLPixelRenderer.cpp # [TODO] placeholder
│ │
│ ├── sound/
│ │ ├── SoundManager.cpp
│ │ └── MusicManager.cpp # [TODO] placeholder
│ │
│ ├── game/
│ │ ├── Player.cpp
│ │ ├── Enemy.cpp
│ │ └── Gameplay.cpp
│ │
│ └── utils/
│ ├── Logger.cpp
│ ├── Config.cpp
│ └── Input.cpp
│
├── assets/
│ ├── images/ # Pac-Man sprites, tiles
│ ├── sounds/ # Sound effects & music
│ └── maps/ # Predefined map files
│
├── examples/ # Example projects / test games
│
├── CMakeLists.txt / Makefile # Build system
└── README.md
```

**Notes on placeholders:**
- `[TODO]` files indicate modules planned for later expansion (e.g., pixel renderer, map history, music manager).
- This structure supports multiple games by adding new folders under `game/` and adding new renderers if needed.

