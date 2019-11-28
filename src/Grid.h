#pragma once
#include <vector>
#include "Node.h"
#include "SFML/Window/Mouse.hpp"


/*
	The grid class is designed to store a 2 dimensional vector of Node objects.
	It's member variables include the width and height of the window, the width
	and height of the grid, a pointer to the current window, and the 2D vector
	of Node objects.

	1)
	A Grid object should be constructed with a pointer to the window where the grid
	should be drawn on and the width and the height of the desired grid. The 2d
	vector of Nodes must first be constructed by resizing the vector to the desired
	width and height. Then, using the "init_grid()" function will fill the 2d vector with
	Node objects. Lastly, the "update_grid_layout()" function should be called to set the
	size and position of each of the Node objects.

	2)
	The resize(int width, int height) should be used to change the size of the grid whenever
	the user desires. It should retain information about the grid before and after the function
	is called. For example, if there is a Node with a NodeState == wall and it's position is 
	(10, 10) on the graph, when the grid is resized from being 14x14 to 20x20, that Node should
	still be (10, 10) on the grid after the resize.

	3)
	The update_grid_layout() function is in charge of resizing and handling the positions for
	each Node::Rectangle on the grid. the grid only needs to be updated when changes are made
	to it. Updating the grid every render cycle will slow down the program so stray away from
	doing multiple calls of the function consecutively if you don't need to.

	4)
	The draw_grid() function draws each Node in the grid onto the Window
*/

class Grid
{
private:
	std::vector< std::vector < Node* > > grid; // 2d vector of Nodes

	unsigned int w_width = 0,	// width of the open window
			w_height = 0,		// height of the open window
			grid_width = 0,		// width of grid
			grid_height = 0;	// height of grid

	unsigned int s_x = -1,		// x position of start, set to -1 to not be on the grid
			s_y = 0,			// y position of start, value is irrelevant 
			d_x = -1,			// x position of destination, set to -1 to not be on the grid
			d_y = 0;			// y position of destination, value is irrelevant

	bool running = false;	// Flag for if the best path is currently being looked for

	sf::RenderWindow* window;	// main window for the program

public:
	Grid(sf::RenderWindow* window, unsigned int grid_width, unsigned int grid_height);
	
	// init_grid() initializes the grid with new Node objects
	// calls update_grid_layout() to set the size and position of
	// the Node objects
	void init_grid();

	// Returns the node at a position given
	Node get_node(int x, int y);

	/* This function resizes the grid while maintaining
		the information held in the old grid, that way
		information about the NodeState for each Node
		object isn't lost.
	*/
	void resize(int width, int height);

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void update_grid_layout();

	// USE UPDATE_GRID_LAYOUT BEFORE DRAWING GRID IF GRID WAS CHANGED
	void draw_grid();

	// Setters
	void set_node_state(int x, int y, NodeState state);

	// Getters
	const bool is_running();
	const int get_width();
	const int get_height();
	const int get_rect_width();
	const int get_rect_height();
	const sf::Vector2i get_mouse_pos_in_grid(sf::Vector2i mouse_pos);
	/*
		TODO:
		- Start working on the algorithm
	*/

};
