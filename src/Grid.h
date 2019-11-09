#pragma once
#include <vector>
#include "Node.h"

class Grid
{
private:
	std::vector< std::vector < Node* > > grid; // 2d vector of Nodes
	int grid_width;	// width of grid
	int grid_height;	// height of grid

public:
	const sf::RectangleShape PLAIN_RECT = sf::RectangleShape(sf::Vector2f(0, 0));
	void resize(int width, int height, int w_width, int w_height);

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void update_grid_layout(int w_width, int w_height);

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void draw_grid();

	const int get_width();
	const int get_height();
};
