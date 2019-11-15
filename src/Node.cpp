#pragma once
#include <iostream>
#include "Node.h"

// Constructor
Node::Node()
{
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0f);
	set_state(NodeState::open);
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
		rect.setFillColor(sf::Color(64, 64, 64));		// set rect to dark grey
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


