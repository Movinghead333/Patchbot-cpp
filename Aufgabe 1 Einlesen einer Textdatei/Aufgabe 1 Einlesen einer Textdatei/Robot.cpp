#include "robot.h"

// Robot-constructor implementation
Robot::Robot(const int p_x_coordinate, const int p_y_coordinate, const RobotType p_robot_type) :
	m_x_coordinate(p_x_coordinate), m_y_coordinate(p_y_coordinate), m_robot_type(p_robot_type)
{
}
const int Robot::get_x_coordinate() const
{
	return m_x_coordinate;
}

const int Robot::get_y_coordinate() const
{
	return m_y_coordinate;
}

const RobotType Robot::get_robot_type() const
{
	return m_robot_type;
}

