#include "point.h"

Point2D::Point2D(int p_x, int p_y)
	:
	x(p_x),
	y(p_y)
{
}

bool Point2D::operator==(Point2D p_point)
{
	return x == p_point.x && y == p_point.y;
}
