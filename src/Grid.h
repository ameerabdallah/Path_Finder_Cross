#pragma once
#include <vector>
#include "Node.h"

class Grid
{
private:
	const sf::RectangleShape PLAIN_RECT = sf::RectangleShape(sf::Vector2f(0, 0));
	unsigned int w_width = 0, w_height = 0; // Window width and window height
	sf::RenderWindow* window;
	std::vector< std::vector < Node* > > grid; // 2d vector of Nodes
	unsigned int grid_width = 0;	// width of grid
	unsigned int grid_height = 0;	// height of grid

public:
	Grid(sf::RenderWindow* window, unsigned int grid_width, unsigned int grid_height);
	void initGrid();

	void resize(int width, int height);

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void update_grid_layout();

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void draw_grid();

	const int get_width();
	const int get_height();
};
