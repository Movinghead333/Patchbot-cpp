#ifndef __ROBOT_H_DEFINED__
#define __ROBOT_H_DEFINED__

#include "robot_type.h"

// A base-class for all robots holding the core functionalities like position and robot-type
class Robot
{
public:

	Robot(const int p_x_coordinate, const int p_y_coordinate, RobotType pRobotType);

	int get_x_coordinate();

	int get_y_coordinate();

	RobotType get_robot_type();


private:

	// A robot's coordinates starting from (0, 0) representing the tile in top left corner
	int m_x_coordinate;
	int m_y_coordinate;

	// A robot's type for later runtime-comparisons
	RobotType m_robot_type;
};

#endif
