#ifndef __NODE_H_DEFINED__
#define __NODE_H_DEFINED__

struct Node
{
	int m_x;
	int m_y;
	int m_distance;

	Node(int p_x, int p_y, int p_distance);

	bool operator<(const Node& other_node) const;
};

#endif