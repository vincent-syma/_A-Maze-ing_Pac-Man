# ==========================================
# Project
# ==========================================

NAME = pacman_game

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

# ==========================================
# Directories
# ==========================================

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
SDL_SRC_DIR = .sdl_src

# ==========================================
# Sources
# ==========================================

SRC = \
$(SRC_DIR)/main.cpp \
$(SRC_DIR)/debug/MazeHistory.cpp \
$(SRC_DIR)/engine/Engine.cpp \
$(SRC_DIR)/maze/Maze.cpp \
$(SRC_DIR)/maze/MazeEditor.cpp \
$(SRC_DIR)/maze/MazeGenerator.cpp \
$(SRC_DIR)/map/Map.cpp \
$(SRC_DIR)/map/BoolOverlay.cpp \
$(SRC_DIR)/map/MapEditor.cpp \
$(SRC_DIR)/render/SDLRenderer.cpp \
$(SRC_DIR)/games/pacman/PacmanGame.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# ==========================================
# Includes
# ==========================================

INCLUDES = -I$(INC_DIR) -I$(SRC_DIR) -I$(BUILD_DIR)/include

# ==========================================
# SDL Libraries
# ==========================================

SDL_LIB = -L$(BUILD_DIR)/lib \
-lSDL3 \
-lSDL3_image \
-lSDL3_ttf \
-lSDL3_mixer

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	SDL_LIB += -Wl,-rpath,@executable_path/$(BUILD_DIR)/lib
endif

# ==========================================
# Build Rules
# ==========================================

all: sdl $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(SDL_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# ==========================================
# SDL Build
# ==========================================

sdl:
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "Building SDL stack..."; \
		mkdir -p $(SDL_SRC_DIR); \
		git clone https://github.com/libsdl-org/SDL.git $(SDL_SRC_DIR)/SDL; \
		git clone https://github.com/libsdl-org/SDL_image.git $(SDL_SRC_DIR)/SDL_image; \
		git clone https://github.com/libsdl-org/SDL_ttf.git $(SDL_SRC_DIR)/SDL_ttf; \
		git clone https://github.com/libsdl-org/SDL_mixer.git $(SDL_SRC_DIR)/SDL_mixer; \
		mkdir -p $(BUILD_DIR); \
		cd $(SDL_SRC_DIR)/SDL && cmake -B build -DCMAKE_INSTALL_PREFIX=$(PWD)/$(BUILD_DIR) && cmake --build build --target install; \
		cd ../SDL_image && cmake -B build -DCMAKE_INSTALL_PREFIX=$(PWD)/$(BUILD_DIR) && cmake --build build --target install; \
		cd ../SDL_ttf && cmake -B build -DCMAKE_INSTALL_PREFIX=$(PWD)/$(BUILD_DIR) && cmake --build build --target install; \
		cd ../SDL_mixer && cmake -B build -DCMAKE_INSTALL_PREFIX=$(PWD)/$(BUILD_DIR) && cmake --build build --target install; \
		echo "SDL stack built."; \
	else \
		echo "SDL already built."; \
	fi

# ==========================================
# Cleaning
# ==========================================

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(BUILD_DIR)
	rm -rf $(SDL_SRC_DIR)

re: fclean all

# ==========================================
# Dependency files
# ==========================================

-include $(DEP)

.PHONY: all clean fclean re sdl