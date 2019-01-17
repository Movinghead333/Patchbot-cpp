#include "node.h"

// constructor which takes in the coordinates of a tile and their distance to
// the starting Node
Node::Node(
	int p_x,
	int p_y,
	int p_distance)
	:
	m_x(p_x),
	m_y(p_y),
	m_distance(p_distance)
{
}

// compares two Node object based on their distance to the original starting
// Node
bool Node::operator<(const Node & other_node) const
{
	return other_node.m_distance < m_distance;
}
