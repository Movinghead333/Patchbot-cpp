#include "node.h"

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

bool Node::operator<(const Node & other_node) const
{
	return other_node.m_distance < m_distance;
}
