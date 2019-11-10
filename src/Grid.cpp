#include "Grid.h"
#include <iostream>

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

	initGrid();
	update_grid_layout();
}

void Grid::initGrid()
{
	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{
			grid[x][y] = new Node();
		}
	}
}

void Grid::resize(int new_width, int new_height)
{
	int prev_width = grid_width;
	int prev_height = grid_height;

	grid_width = new_width;
	grid_height = new_height;

	// Resize the vector
	grid.resize(new_width);
	for (int i = 0; i < new_width; i++)
	{
		grid[i].resize(new_height);
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

	// If the new_height is larger after resize but new_width is >= prev_width
	if (new_height > prev_height && new_width <= prev_width)
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
	if (new_width > prev_width && new_height > prev_height)
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


// Update Grid Layout
void Grid::update_grid_layout()
{
	float rect_width = w_width / float(grid_width),
		rect_height = w_height / float(grid_height);

	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{
			grid[x][y]->rect.setSize(sf::Vector2f(rect_width, rect_height));
			grid[x][y]->rect.setPosition(sf::Vector2f(rect_width * x, rect_height * y));
			std::cout << grid[x][y]->rect.getSize().x;
		}

	}
}

void Grid::draw_grid()
{
	for (int x = 0; x < grid_width; x++)
	{
		for (int y = 0; y < grid_height; y++)
		{

			window->draw(grid[x][y]->rect);

		}
	}
}

const int Grid::get_width()
{
	return grid_width;
}

const int Grid::get_height()
{
	return grid_height;
}
