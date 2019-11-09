#pragma once
#include <SFML/Graphics.hpp>
#include "NodeState.h"

class Node
{
private:
	// Colors

	sf::RectangleShape rect;	// Rectangle Associated with Node
	NodeState state;			// State of Node

	void set_rect_color(sf::Color col);

public:
	Node(sf::RectangleShape rect, NodeState state = NodeState::open);

	void set_state(NodeState state);
	const NodeState get_state();

	void set_rect_size(sf::Vector2f vect);
	void set_rect_pos(sf::Vector2f vect);
	const sf::RectangleShape get_rect();
	const sf::Vector2f get_rect_pos();
};