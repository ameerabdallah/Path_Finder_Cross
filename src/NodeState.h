#pragma once
enum class NodeState
{
	open,			// white
	wall,			// dark grey
	start,			// cyan
	destination,	// yellow
	path			// green
};