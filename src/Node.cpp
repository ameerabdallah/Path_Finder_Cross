#pragma once
#include <iostream>
#include <cmath>
#include "Node.h"

// Constructor
Node::Node(int x, int y)
{
	position = sf::Vector2i(x, y);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0f);
	set_state(NodeState::open);
	s_cost = 0;
	d_cost = 0;
	t_cost = 0;
}


// Setters
void Node::set_state(NodeState state)
{
	this->state = state;
	switch (state)
	{
	case NodeState::open:
		rect.setFillColor(sf::Color::White);			// set rect to white
		break;
	case NodeState::wall:
		rect.setFillColor(sf::Color(30, 30, 30));		// set rect to dark grey
		break;
	case NodeState::start:
		rect.setFillColor(sf::Color::Cyan);				// set rect to cyan
		break;
	case NodeState::destination:
		rect.setFillColor(sf::Color::Yellow);			// set rect to yellow
		break;
	case NodeState::path:
		rect.setFillColor(sf::Color::Green);			// set rect to green
		break;
	}
}

void Node::set_rect_color(sf::Color color)
{
	rect.setFillColor(color);
}

void Node::set_rect_position(sf::Vector2f position)
{
	rect.setPosition(position);
}

void Node::set_rect_size(sf::Vector2f size)
{
	rect.setSize(size);
}

void Node::set_s_cost(sf::Vector2i start)
{
	// the deltas are the distances between the respective coordinate
	float delta_x = start.x - position.x;
	float delta_y = start.y - position.y;

	s_cost = std::sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

void Node::set_d_cost(sf::Vector2i destination)
{
	// the deltas are the distances between the respective coordinate
	float delta_x = destination.x - position.x;
	float delta_y = destination.y - position.y;

	d_cost = std::sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

void Node::set_t_cost()
{
	t_cost = s_cost + d_cost;
}


// Getters
const NodeState Node::get_state()
{
	return state;
}

const sf::Color Node::get_rect_color()
{
	return rect.getFillColor();
}

const sf::Vector2f Node::get_rect_position()
{
	return rect.getPosition();
}

const sf::Vector2f Node::get_rect_size()
{
	return rect.getSize();
}

const sf::RectangleShape Node::get_rectangle()
{
	return rect;
}

const float Node::get_s_cost()
{
	return s_cost;
}

const float Node::get_d_cost()
{
	return d_cost;
}

const float Node::get_t_cost()
{
	return t_cost;
}
