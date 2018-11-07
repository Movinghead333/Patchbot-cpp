#ifndef __ROBOT_H_DEFINED__
#define __ROBOT_H_DEFINED__

#include "robot_type.h"

// A base-class for all robots holding the core functionalities like position and robot-type
class Robot
{
public:

	// constructor
	Robot(const int p_x_coordinate, const int p_y_coordinate, const RobotType pRobotType);

	// getter methods for member-fields
	const int get_x_coordinate() const;

	const int get_y_coordinate() const;

	const RobotType get_robot_type() const;


private:

	// A robot's coordinates starting from (0, 0) representing the tile in top left corner
	int m_x_coordinate;
	int m_y_coordinate;

	// A robot's type for later runtime-comparisons
	const RobotType m_robot_type;
};

#endif
