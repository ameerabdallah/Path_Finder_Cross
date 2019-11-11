#pragma once
#include <SFML/Graphics.hpp>
#include "NodeState.h"

class Node
{
private:	
	
	sf::RectangleShape rect;	// Rectangle Associated with Node

	NodeState state;	// State of Node

public:
	
	// Constructor
	Node();

	// Setters
	void set_state(NodeState state);
	void set_rect_color(sf::Color color);
	void set_rect_position(sf::Vector2f position);
	void set_rect_size(sf::Vector2f size);

	// Getters
	const NodeState get_state();
	const sf::Color get_rect_color();
	const sf::Vector2f get_rect_position();
	const sf::Vector2f get_rect_size();
	const sf::RectangleShape get_rectangle();
};
