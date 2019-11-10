#pragma once
#include "Node.h"

void Node::set_rect_color(sf::Color col)
{
	rect.setFillColor(col);
}

Node::Node()
{
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0f);
	set_state(NodeState::open);
}

void Node::set_state(NodeState state)
{
	this->state = state;
	switch (state)
	{
	case NodeState::open:
		set_rect_color(sf::Color::White);			// set rect to white
	case NodeState::wall:
		set_rect_color(sf::Color(64, 64, 64));		// set rect to dark grey
	case NodeState::start:
		set_rect_color(sf::Color::Cyan);			// set rect to cyan
	case NodeState::destination:
		set_rect_color(sf::Color::Yellow);			// set rect to yellow
	case NodeState::path:
		set_rect_color(sf::Color::Green);			// set rect to green
	}
}

const NodeState Node::get_state()
{
	return state;
}

const sf::Vector2f Node::get_rect_pos()
{
	return rect.getPosition();
}
