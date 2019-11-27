#include "Grid.h"
#include <iostream>

// Constructor
Grid::Grid(sf::RenderWindow* window, unsigned int grid_width, unsigned int grid_height)
{
	this->window = window;
	w_width = this->window->getSize().x;
	w_height = this->window->getSize().y;

	this->grid_width = grid_width;
	this->grid_height = grid_height;
	
	grid.resize(grid_width);
	for (int i = 0; i < grid_width; i++)
	{
		grid[i].resize(grid_height);
	}

	init_grid();
}


// init_grid() initializes the grid with new Node objects and
// calls update_grid_layout() to set the size and position of
// the Node objects
void Grid::init_grid()
{
	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{
			grid[x][y] = new Node();
		}
	}
	update_grid_layout();
}

Node Grid::get_node(int x, int y)
{
	return *grid[x][y];
}

/* This function resizes the grid while maintaining
   the information held in the old grid, that way
   information about the states of each Node don't
   disappear*/
void Grid::resize(int new_width, int new_height)
{
	int prev_width = grid_width;
	int prev_height = grid_height;

	grid_width = new_width;
	grid_height = new_height;

	// Resize the vector
	grid.resize(new_width);
	for (int x = 0; x < new_width; x++)
	{
		grid[x].resize(new_height);
	}

	/*
	Now that the grid size is changed, we determine
	whether this new grid size is larger or smaller
	than the previous grid size. If it is smaller, 
	nothing needs to be done, if it is larger, the new 
	Nodes in the grid must be initialized
	*/

	// If the new_width is larger after resize but new_height is >= prev_height
	if (new_width > prev_width && new_height <= prev_height)
	{
		for (int x = prev_width; x < new_width; x++)
		{
			for (int y = 0; y < new_height; y++)
			{
				grid[x][y] = new Node();
			}
		}
	}

	// If the new_height is larger after resize but new_width is <= prev_width
	else if (new_height > prev_height && new_width <= prev_width)
	{
		for (int x = 0; x < new_width; x++)
		{
			for (int y = prev_height; y < new_height; y++)
			{
				grid[x][y] = new Node();
			}
		}
	}

	// If the new_width is > prev_width and new_height is > prev_height
	else if (new_width > prev_width && new_height > prev_height)
	{
		// Fill in new grid space for width
		for (int x = prev_width; x < new_width; x++)
		{
			for (int y = 0; y < new_height; y++)
			{
				grid[x][y] = new Node();
			}
		}

		// Fill in new grid space for height
		for (int x = 0; x < new_width; x++)
		{
			for (int y = prev_height; y < new_height; y++)
			{
				grid[x][y] = new Node();
			}
		}
	}

	update_grid_layout();
}


// Sets the size and position of each Node/rectangle on the grid
void Grid::update_grid_layout()
{

	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{
			grid[x][y]->set_rect_size(sf::Vector2f(get_rect_width(), get_rect_height()));
			grid[x][y]->set_rect_position(sf::Vector2f(get_rect_width() * x, get_rect_height() * y));
		}
	}
}


// This function draws each rectangle in the grid to the window member variable
void Grid::draw_grid()
{
	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{
			window->draw(grid[x][y]->get_rectangle());
		}
	}
}

// Setters

void Grid::set_node_state(int x, int y, NodeState state)
{
	grid[x][y]->set_state(state);
}

// Getters
const int Grid::get_width()
{
	return grid_width;
}

const int Grid::get_height()
{
	return grid_height;
}

const float Grid::get_rect_width()
{
	return window->getSize().x / (float)grid_width;
}

const float Grid::get_rect_height()
{
	return window->getSize().y / (float)grid_height;

}

const sf::Vector2i Grid::get_mouse_pos_in_grid(sf::Vector2i mouse_pos)
{
	int grid_x = mouse_pos.x / get_rect_width();
	int grid_y = mouse_pos.y / get_rect_height();

	std::printf("(%d, %d)", grid_x, grid_y);
	return sf::Vector2i(grid_x, grid_y);
}