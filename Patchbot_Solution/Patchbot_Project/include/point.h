#ifndef __POINT_H_DEFINED__
#define __POINT_H_DEFINED__

struct Point2D
{
	Point2D(int p_x, int p_y);
	int x;
	int y;

	bool operator ==(Point2D p_point);
};

#endif