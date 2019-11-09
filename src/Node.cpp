#pragma once
#include "Node.h"

void Node::set_rect_color(sf::Color col)
{
	rect.setFillColor(col);
}

Node::Node(sf::RectangleShape rect, NodeState state)
{
	this->rect = rect;
	this->state = state;
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

void Node::set_rect_size(sf::Vector2f vect)
{
	rect.setSize(vect);
}

void Node::set_rect_pos(sf::Vector2f vect)
{
	rect.setPosition(vect);
}

const sf::RectangleShape Node::get_rect()
{
	return rect;
}

const sf::Vector2f Node::get_rect_pos()
{
	return rect.getPosition();
}
