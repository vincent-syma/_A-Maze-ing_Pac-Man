# =========================
# Project
# =========================
NAME        = graphic_map
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror

# =========================
# Directories
# =========================
SRCS_DIR    = srcs
INCS_DIR    = includes
SDL_DIR     = build

SRCS = \
	$(SRCS_DIR)/main.cpp \
	$(SRCS_DIR)/MazeGenerator.cpp \
	$(SRCS_DIR)/Visualiser.cpp \
	$(SRCS_DIR)/Maze.cpp \
	$(SRCS_DIR)/Map.cpp \
	$(SRCS_DIR)/Graphic.cpp

OBJS = $(SRCS:.cpp=.o)

# =========================
# SDL3
# =========================
SDL_INC     = -I$(SDL_DIR)/include
SDL_LIB     = -L$(SDL_DIR)/lib -lSDL3

# macOS specific
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	SDL_LIB += -Wl,-rpath,@executable_path/$(SDL_DIR)/lib
endif

# =========================
# Includes
# =========================
INCLUDES = -I$(INCS_DIR) $(SDL_INC)

# =========================
# Rules
# =========================
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(SDL_LIB) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re