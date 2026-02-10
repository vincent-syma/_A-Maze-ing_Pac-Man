#include <cstdint>
#include <iostream>
#include "shared.hpp"
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

	mg.generate_maze();
	// std::vector<std::vector<Cell>> maze_history = mg.share_history();
	// visualise_maze(maze_history, width, height);
	std::vector<Maze> maze_history = mg.share_maze_history();
	visualise_maze(maze_history);
	// generate maze
	// remove dead ends
	// increase connectivity (add loops)
	// decrease connectivity (remove loops)
	// double and flip horizontally/vertically

	// convert maze to map
	// add ghost area
	// add portals
	return (0);
}