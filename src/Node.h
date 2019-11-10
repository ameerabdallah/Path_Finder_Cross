#pragma once
#include <SFML/Graphics.hpp>
#include "NodeState.h"

class Node
{
private:
	
	// Colors
	NodeState state = NodeState::open;			// State of Node

	void set_rect_color(sf::Color col);

public:
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(0, 0));	// Rectangle Associated with Node
	Node();

	void set_state(NodeState state);
	const NodeState get_state();
	const sf::Vector2f get_rect_pos();
};
