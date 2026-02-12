#ifndef SHARED_HPP
#define SHARED_HPP

#include <cstdint>

uint32_t const COLOURS[5] = {
    0x333333FF, // EMPTY
    0x007F00FF, // PROCESSING
    0x0000FFFF, // PATH
    0xFFFF0000, // START
    0xFFFFFFFF  // END
};

enum class CellType {
    EMPTY,
    PROCESSING,
    PATH,
    START,
    END
};

enum class ConnectionNumber : uint8_t {
    NONE,
    ONE,
    TWO,
    THREE,
    FOUR
};

enum class Direction : uint8_t {
    North = 1,
    East  = 2,
    South = 4,
    West  = 8
};

enum class Directions : uint8_t {
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3
};

char const * const  BLOCKS1[16] = {" ", "║", "═", "╚", "║", "║", "╔", "╠", "═", "╝", "═", "╩", "╗", "╣", "╦", "╬"};
char const * const  BLOCKS2[16] = {"•", "╵", "╶", "└", "╷", "│", "┌", "├", "╴", "┘", "─", "┴", "┐", "┤", "┬", "┼"};
char const * const  BLOCKS3[16] = {"  ", "║ ", "══", "╚═", "║ ", "║ ", "╔═", "╠═", "═ ", "╝ ", "══", "╩═", "╗ ", "╣ ", "╦═", "╬═"};
char const * const  BLOCKS4[16] = {"• ", "╵ ", "╶─", "└─", "╷ ", "│ ", "┌─", "├─", "╴ ", "┘ ", "──", "┴─", "┐ ", "┤ ", "┬─", "┼─"};

#define ANSII_RESET   "\033[0m"
#define ANSII_RED     "\033[31m"
#define ANSII_GREEN   "\033[32m"
#define ANSII_YELLOW  "\033[33m"
#define ANSII_BLUE    "\033[34m"
#define ANSII_MAGENTA "\033[35m"
#define ANSII_CYAN    "\033[36m"
#define ANSII_WHITE   "\033[37m"
#define ANSII_BLACK   "\033[30m"
#define ANSII_BG_RED     "\033[41m"
#define ANSII_BG_GREEN   "\033[42m"
#define ANSII_BG_YELLOW  "\033[43m"
#define ANSII_BG_BLUE    "\033[44m"
#define ANSII_BG_MAGENTA "\033[45m"
#define ANSII_BG_CYAN    "\033[46m"
#define ANSII_BG_WHITE   "\033[47m"
#define ANSII_BG_BLACK   "\033[40m"
#define ANSII_BOLD      "\033[1m"
#define ANSII_UNDERLINE "\033[4m"

#define ANSII_ENTER_ALTERNATE_SCREEN "\033[?1049h"
#define ANSII_EXIT_ALTERNATE_SCREEN  "\033[?1049l"

#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_CURSOR_HOME  "\033[H"
#define ANSI_HIDE_CURSOR   "\033[?25l"
#define ANSI_SHOW_CURSOR   "\033[?25h"


#define DEBUG 0 // set to 1 to enable debug output


struct Cell {
    bool visited = false;
    uint8_t status = 0; // 0 = new, 1 = working, 2 = finished
    uint8_t connectionNumber = 0;
    uint8_t connections = 0;  // bitmask for connections: 1 = North, 2 = East, 4 = South, 8 = West
};

// maze struct
// maybe should be class?
class Maze {
public:
    Maze() = delete;
    Maze(const Maze&) = default;
    Maze& operator=(const Maze&) = delete;
    Maze(Maze&&) = default;
    Maze& operator=(Maze&&) = delete;
    Maze(uint16_t width, uint16_t height) : width(width), height(height), cells(width * height) {};
    ~Maze() = default;

    uint16_t get_width() const { return width; }
    uint16_t get_height() const { return height; }
    std::vector<Cell> get_cells() const { return cells; }
    bool connectEast(uint16_t x, uint16_t y) {
        if (x < width - 1) {
            if (cells[y * width + x].connections & 2) {
                return false; // Already connected East
            }
            cells[y * width + x].connections |= 2;     // Connect East
            cells[y * width + x].connectionNumber += 1;
            cells[y * width + (x + 1)].connections |= 8; // Connect West
            cells[y * width + (x + 1)].connectionNumber += 1;
            return true;
        }
        return false;
    }
    bool connectWest(uint16_t x, uint16_t y) {
        if (x > 0) {
            if (cells[y * width + x].connections & 8) {
                return false; // Already connected West
            }
            cells[y * width + x].connections |= 8;     // Connect West
            cells[y * width + x].connectionNumber += 1;
            cells[y * width + (x - 1)].connections |= 2; // Connect East
            cells[y * width + (x - 1)].connectionNumber += 1;
            return true;
        }
        return false;
    }
    bool connectNorth(uint16_t x, uint16_t y) {
        if (y > 0) {
            if (cells[y * width + x].connections & 1) {
                return false; // Already connected North
            }
            cells[y * width + x].connections |= 1;     // Connect North
            cells[y * width + x].connectionNumber += 1;
            cells[(y - 1) * width + x].connections |= 4; // Connect South
            cells[(y - 1) * width + x].connectionNumber +=  1;
            return true;
        }
        return false;
    }
    bool connectSouth(uint16_t x, uint16_t y) {
        if (y < height - 1) {
            if (cells[y * width + x].connections & 4) {
                return false; // Already connected South
            }
            cells[y * width + x].connections |= 4;     // Connect South
            cells[y * width + x].connectionNumber += 1;
            cells[(y + 1) * width + x].connections |= 1; // Connect North
            cells[(y + 1) * width + x].connectionNumber += 1;
            return true;
        }
        return false;
    }
    bool visit_cell(uint16_t x, uint16_t y) {
        if (x < width && y < height && cells[y * width + x].visited == false) {
            cells[y * width + x].visited = true;
            return true;
        }
        return false;
    }
    Cell& get_cell(uint16_t x, uint16_t y) { return cells[y * width + x]; }
    const Cell& get_cell(uint16_t x, uint16_t y) const { return cells[y * width + x]; }

    void flip_vertically() {
        uint16_t new_width = width * 2 - 1;
        uint16_t new_height = height;
        std::vector<Cell> new_cells(new_width * new_height);
        for (uint16_t y = 0; y < height; ++y) {
            for (uint16_t x = 0; x < width; ++x) {
                new_cells[y * new_width + x] = cells[y * width + x];
            }
            if (new_cells[y * new_width + width - 1].connections & 8) {
                new_cells[y * new_width + width - 1].connections |= 2; // add west connection if east connection was present
                new_cells[y * new_width + width - 1].connectionNumber += 1;
            }
            for (uint16_t x = new_width - 1; x >= width; --x) {
                new_cells[y * new_width + x] = cells[y * width + (width - 1 - (x - width + 1))];
                uint8_t connections = new_cells[y * new_width + x].connections;
                new_cells[y * new_width + x].connections &= 5; // keep north and south connections, remove east and west
                new_cells[y * new_width + x].connections |= (connections & 2) * 4; // add east connection if west connection was present
                new_cells[y * new_width + x].connections |= (connections & 8) / 4; // add west connection if east connection was present
            }
        }
        cells = std::move(new_cells);
        width = new_width;
        height = new_height;
    };

    void flip_horizontally() {
        uint16_t new_width = width;
        uint16_t new_height = height * 2 - 1;
        std::vector<Cell> new_cells(new_width * new_height);
        for (uint16_t y = 0; y < height; ++y) {
            for (uint16_t x = 0; x < width; ++x) {
                new_cells[y * new_width + x] = cells[y * width + x];
            }
        }
        for (uint16_t x = 0; x < width; ++x) {
            if (new_cells[(height - 1) * new_width + x].connections & 1) {
                    new_cells[(height - 1) * new_width + x].connections |= 4; // add south connection if north connection was present
                    new_cells[(height - 1) * new_width + x].connectionNumber += 1;
            }
        }
        for (uint16_t y = height; y < new_height; ++y) {
            for (uint16_t x = 0; x < width; ++x) {
                new_cells[y * new_width + x] = cells[(height - 1 - (y - height + 1)) * width + x];
                uint8_t connections = new_cells[y * new_width + x].connections;
                new_cells[y * new_width + x].connections &= 10; // keep east and west connections, remove north and south
                new_cells[y * new_width + x].connections |= (connections & 1) * 4; // add north connection if south connection was present
                new_cells[y * new_width + x].connections |= (connections & 4) / 4; // add south connection if north connection was present
            }
        }
        cells = std::move(new_cells);
        width = new_width;
        height = new_height;
    };

private:
    uint16_t width;
    uint16_t height;
    std::vector<Cell> cells;
};

#endif // SHARED_HPP