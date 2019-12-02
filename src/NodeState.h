#pragma once
enum class NodeState
{
	open,			// white
	wall,			// dark grey
	start,			// cyan
	destination,	// yellow
	unvisited,
	visited,
	path,			// green
};