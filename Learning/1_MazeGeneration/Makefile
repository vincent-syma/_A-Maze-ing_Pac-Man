SOURCES = srcs/main.cpp srcs/MazeGenerator.cpp srcs/Visualiser.cpp srcs/Maze.cpp
HEADERS = includes/shared.hpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
NAME = maze_generator
OBJ = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -Iincludes -c $< -o $@

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re