#ifndef __NODE_H_DEFINED__
#define __NODE_H_DEFINED__

// data struct Node used for calculating the dijkstra algorithm for pathfinding
struct Node
{
	// x coordinate of the represented tile
	int m_x;
	// x coordinate of the represented tile
	int m_y;

	// distance needed to calculate the dijkstra algorithm
	int m_distance;

	// parameterized constructor
	Node(int p_x, int p_y, int p_distance);

	// less operator needed for use in std::priority_queue
	bool operator<(const Node& other_node) const;
};

#endif