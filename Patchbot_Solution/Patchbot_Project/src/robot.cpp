#include "robot.h"

// Robot-constructor implementation
Robot::Robot(
	int p_x_coordinate,
	int p_y_coordinate,
	RobotType p_robot_type) :
	m_x_coordinate(p_x_coordinate),
	m_y_coordinate(p_y_coordinate),
	m_back_up_x(p_x_coordinate),
	m_back_up_y(p_y_coordinate),
	m_robot_type(p_robot_type)
{
}
void Robot::update()
{
	std::cout << "robot updated!" << std::endl;
}

void Robot::set_x_coordinate(int p_x)
{
	m_x_coordinate = p_x;
}

int Robot::get_x_coordinate() const
{
	return m_x_coordinate;
}

void Robot::set_y_coordinate(int p_y)
{
	m_y_coordinate = p_y;
}

int Robot::get_y_coordinate() const
{
	return m_y_coordinate;
}

void Robot::set_coordinates(Point2D p_position)
{
	m_x_coordinate = p_position.x;
	m_y_coordinate = p_position.y;
}

RobotType Robot::get_robot_type() const
{
	return m_robot_type;
}

void Robot::update_position(int p_new_x, int p_new_y)
{
	m_x_coordinate = p_new_x;
	m_y_coordinate = p_new_y;
}

void Robot::reset_robot()
{
	m_x_coordinate = m_back_up_x;
	m_y_coordinate = m_back_up_y;
}

void Robot::set_m_blocked(bool p_blocked)
{
	m_blocked = p_blocked;
}

bool Robot::get_m_blocked() const
{
	return m_blocked;
}

