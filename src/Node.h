#pragma once
#include <SFML/Graphics.hpp>
#include "NodeState.h"

/*
	The Node class should hold a RectangleShape called rect and a NodeState called state. The 
	rect object should be modified to visually represent what is going on in the program. It
	also holds information about it's current position in the window, size, color, etc.

	1)
	set_state(NodeState state) sets the state of the node and changes the color of the rectangle
	based on what state it is being changed to
*/

class Node
{
private:	
	
	sf::RectangleShape rect;	// Rectangle Associated with Node

	NodeState state;	// State of Node

	sf::Vector2i position;	// Position of vector

	float s_cost;			// distance from this node to start position
	float d_cost;			// distance from this node to distance position
	float t_cost;			// sum of s_cost and d_cost

public:
	
	// Constructor
	Node(int x, int y);

	// Setters
	void set_state(NodeState state);
	void set_rect_color(sf::Color color);
	void set_rect_position(sf::Vector2f position);
	void set_rect_size(sf::Vector2f size);
	void set_s_cost(sf::Vector2i start);
	void set_d_cost(sf::Vector2i distance);
	void set_t_cost();

	// Getters
	const NodeState get_state();
	const sf::Color get_rect_color();
	const sf::Vector2f get_rect_position();
	const sf::Vector2f get_rect_size();
	const sf::RectangleShape get_rectangle();
	const float get_s_cost();
	const float get_d_cost();
	const float get_t_cost();
};

