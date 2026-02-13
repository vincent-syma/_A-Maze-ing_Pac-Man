#include <cstdint>
#include <iostream>
#include "shared.hpp"
#include "Maze.hpp"
#include "MazeGenerator.hpp"

// void    visualise_maze(std::vector<std::vector<Cell>>& maze_history, uint8_t width, uint8_t height);
void    visualise_maze(std::vector<Maze>& maze_history);


// add options to add seed, width, height, algorithm
int	main(int argc, char* argv[])
{
	uint16_t	height;
	uint16_t	width;
	uint32_t	seed;

	if (argc == 4)
	{
		width = static_cast<uint16_t>(std::stoi(argv[1]));
		height = static_cast<uint16_t>(std::stoi(argv[2]));
		seed = static_cast<uint32_t>(std::stoul(argv[3]));
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <width> <height> <seed>\n";
		return (1);
	}

	// std::cout << std::endl;
	std::cout << "Generating maze of size " << (int)width << "x" << (int)height << " with seed " << seed << std::endl;

	MazeGenerator		mg(width, height, seed);

	// block some cells for later
	mg.visit_cell(width - 1, height - 1);
	mg.visit_cell(width - 2, height - 1);
	mg.visit_cell(width - 1, height - 2);
	mg.visit_cell(width - 2, height - 2);

	//generate maze
	mg.generate_maze();
	
	// remove dead ends
	mg.remove_deadends();

	// increase connections
	mg.increase_connections();
	// flip vertically
	mg.flip_vertically();
	// flip horizontally
	mg.flip_horizontally();

	std::vector<Maze> maze_history = mg.share_maze_history();
	visualise_maze(maze_history);
	// convert maze to map
	// add ghost area
	// add portals
	return (0);
}