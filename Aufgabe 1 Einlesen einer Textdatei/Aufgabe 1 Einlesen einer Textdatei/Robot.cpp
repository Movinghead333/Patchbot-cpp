#include "robot.h"

// Robot-constructor implementation
Robot::Robot(const int p_x_coordinate, const int p_y_coordinate, RobotType p_robot_type) :
	m_x_coordinate(p_x_coordinate), m_y_coordinate(p_y_coordinate), m_robot_type(p_robot_type)
{
}
int Robot::get_x_coordinate()
{
	return m_x_coordinate;
}

int Robot::get_y_coordinate()
{
	return m_y_coordinate;
}

RobotType Robot::get_robot_type()
{
	return m_robot_type;
}

