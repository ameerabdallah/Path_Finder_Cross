#pragma once
#include <vector>
#include "Node.h"

class Grid
{
private:
	std::vector< std::vector < Node* > > grid; // 2d vector of Nodes
	unsigned int w_width = 0,	// width of the open window
			w_height = 0,		// height of the open window
			grid_width = 0,		// width of grid
			grid_height = 0;	// height of grid

	sf::RenderWindow* window;	// main window for the program


public:
	Grid(sf::RenderWindow* window, unsigned int grid_width, unsigned int grid_height);
	
	// initGrid() initializes the grid with new Node objects
	void initGrid();

	/* This function resizes the grid while maintaining
		the information held in the old grid, that way
		information about the states of each Node don't
		disappear*/
	void resize(int width, int height);

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void update_grid_layout();

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void draw_grid();

	// Getters
	const int get_width();
	const int get_height();

	/*
		TODO:
		1) Grid class destructor
		
		2) Adjust the resize(int width, int height) function to delete Nodes
		that have fallen out of scope

		3) Implement a way for the user to interact with the grid in a way that
		allows them to make changes to the Node's state on the grid
			- Keyboard should be used to select the state they want attached to their
			mouse click
			- Mouse should be used to select the position on the grid which they want changed
			- P.S, only allow 1 NodeState::start and 1 NodeState::destination on the grid at
			all times. Also, do not let the user change a position to be path.

		4) Implement a way for the user to change the size of the grid using 2 sliders. 1 slider
		should be used to change the width and the other to change the height.
	*/


};
