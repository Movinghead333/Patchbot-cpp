#include "robot.h"

// Robot-constructor implementation
Robot::Robot(Point2D p_position, RobotType p_robot_type) :
	m_x_coordinate(p_position.x),
	m_y_coordinate(p_position.y),
	m_position_backup(p_position),
	m_robot_type(p_robot_type),
	m_back_up_robot_type(p_robot_type)
{
}
void Robot::update()
{
	std::cout << "robot updated!" << std::endl;
}

void Robot::update_visible_time()
{
	if (time_visible > 0)
	{
		time_visible--;
	}
}

void Robot::setup_visible_time()
{
	time_visible = 5;
}

bool Robot::get_visibility()
{
	return time_visible == 0;
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
	// reset the robot's coordinates
	m_x_coordinate = m_position_backup.x;
	m_y_coordinate = m_position_backup.y;

	// reset RobotType
	m_robot_type = m_back_up_robot_type;

	// reset the robots death-timer
	time_visible = -1;
}

void Robot::set_m_blocked(bool p_blocked)
{
	m_blocked = p_blocked;
}

bool Robot::get_m_blocked() const
{
	return m_blocked;
}

