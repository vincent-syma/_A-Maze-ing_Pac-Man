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
BUILD_DIR   = build
SDL_SRC_DIR = .sdl_src

SRCS = \
	$(SRCS_DIR)/main.cpp \
	$(SRCS_DIR)/MazeGenerator.cpp \
	$(SRCS_DIR)/Visualiser.cpp \
	$(SRCS_DIR)/Maze.cpp \
	$(SRCS_DIR)/Map.cpp \
	$(SRCS_DIR)/Graphic.cpp

OBJS = $(SRCS:.cpp=.o)

# =========================
# SDL3 + extensions
# =========================
SDL_INC = -I$(BUILD_DIR)/include
SDL_LIB = -L$(BUILD_DIR)/lib \
          -lSDL3 \
          -lSDL3_image \
          -lSDL3_ttf \
          -lSDL3_mixer

# macOS rpath
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	SDL_LIB += -Wl,-rpath,@executable_path/$(BUILD_DIR)/lib
endif

# =========================
# Includes
# =========================
INCLUDES = -I$(INCS_DIR) $(SDL_INC)

# =========================
# Rules
all: sdl $(NAME)

# Build SDL stack only if build folder doesn't exist
sdl:
	if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "Building SDL3 stack..."; \
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
		echo "SDL stack built successfully."; \
	else \
		echo "Build folder exists. Skipping SDL build."; \
	fi

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(SDL_LIB) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

# fclean now also removes SDL source and build folders
fclean: clean
	rm -f $(NAME)
	rm -rf $(BUILD_DIR)
	rm -rf $(SDL_SRC_DIR)

re: fclean all

.PHONY: all clean fclean re sdl