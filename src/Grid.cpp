#include "Grid.h"
#include <iostream>

// Constructor
Grid::Grid(sf::RenderWindow* window, unsigned int grid_width, unsigned int grid_height)
{
	start_pos = sf::Vector2i(-1, -1);
	destination_pos = sf::Vector2i(-1, -1);

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
			grid[x][y] = new Node(x, y);
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
				grid[x][y] = new Node(x, y);
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
				grid[x][y] = new Node(x, y);
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
				grid[x][y] = new Node(x, y);
			}
		}

		// Fill in new grid space for height
		for (int x = 0; x < new_width; x++)
		{
			for (int y = prev_height; y < new_height; y++)
			{
				grid[x][y] = new Node(x, y);
			}
		}
	}

	fix_dest_start_positions();
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
			grid[x][y]->set_rect_position(window->mapPixelToCoords(sf::Vector2i(get_rect_width() * x, get_rect_height() * y)));
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

// calculate each node's s_cost, f_cost and t_cost
void Grid::calculate_node_costs()
{
	for (int i = 0; i < grid_width; i++)
	{
		for (int j = 0; j < grid_height; j++)
		{
			grid[i][j]->set_s_cost(start_pos);
			grid[i][j]->set_d_cost(destination_pos);
			grid[i][j]->set_t_cost();

			std::cout << "(" << i << ", " << j << ")\n";
			std::cout << "s_cost: " << grid[i][j]->get_s_cost() << std::endl;
			std::cout << "d_cost: " << grid[i][j]->get_d_cost() << std::endl;
			std::cout << "t_cost: " << grid[i][j]->get_t_cost() << std::endl << std::endl;
		}
	}
}

// check if the destination_pos and start_pos are within the bounds of the grid
// and if they aren't set the position to -1, -1
void Grid::fix_dest_start_positions()
{
	if (destination_pos.x > grid_width || destination_pos.y > grid_height)
		destination_pos = sf::Vector2i(-1, -1);
	
	if (start_pos.x > grid_width || start_pos.y > grid_height)
		start_pos = sf::Vector2i(-1, -1);
}

// A* Algorithm for finding the fastest path between the start_pos and destination_pos
void Grid::run_a_star()
{
	running = true; // it is necessary to set the running flag to true so that user input is 
					// not accepted while the algorithm is being run

	// Check if the function is able to be run
	if (destination_pos.x == -1 || start_pos.x == -1)
	{
		std::cout << "Please input the start and destination position before attempting to run the a* path finder\n";
		running = false;
		return; // exit out of function
	}

	// Necesssary so that all of the costs can be compared between nodes
	calculate_node_costs();

	/*
	TODO:

	-IMPLEMENT A-STAR PATHFINDER
	*/


	running = false; // This should be the last command
}

// Setters
void Grid::set_node_state(int x, int y, NodeState state)
{
	grid[x][y]->set_state(state);
	if (state == NodeState::start) {

		// sets the old start position as NodeState::open instead of NodeState::start
		if (start_pos.x != -1 || start_pos.y != -1)
			grid[start_pos.x][start_pos.y]->set_state(NodeState::open);

		start_pos = sf::Vector2i(x, y);
	}
	else if (state == NodeState::destination) {

		// sets the old destination position as NodeState::open instead of NodeState::destination
		if (destination_pos.x != -1 || destination_pos.y != -1) 
			grid[destination_pos.x][destination_pos.y]->set_state(NodeState::open);

		destination_pos = sf::Vector2i(x, y);
	}
}



// Getters
const bool Grid::is_running()
{
	return running;
}

const int Grid::get_width()
{
	return grid_width;
}

const int Grid::get_height()
{
	return grid_height;
}

const int Grid::get_rect_width()
{
	return 50;
}

const int Grid::get_rect_height()
{
	return 50;
}

const sf::Vector2i Grid::get_mouse_pos_in_grid(sf::Vector2i mouse_pos)
{
	int grid_x = mouse_pos.x / get_rect_width();
	int grid_y = mouse_pos.y / get_rect_height();

	return sf::Vector2i(grid_x, grid_y);
}
