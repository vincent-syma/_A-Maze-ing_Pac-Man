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

enum class CellType :uint8_t {
    EMPTY,
    PROCESSING,
    PATH,
    START,
    END,
    WALL,
    CELL_TYPE_COUNT
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





#endif // SHARED_HPP