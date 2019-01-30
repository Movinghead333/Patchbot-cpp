#include "robot.h"
#include "colony.h"

// Robot-constructor implementation
Robot::Robot(const Point2D& p_position, RobotType p_robot_type) :
	m_position(p_position),
	m_position_backup(p_position),
	m_robot_type(p_robot_type),
	m_back_up_robot_type(p_robot_type)
{
}
void Robot::update(Colony& p_colony)
{
	std::cout << "robot updated!" << std::endl;
}

bool Robot::check_collision(Tile& p_target_tile)
{
	//TODO change to interface
	std::cout << "unimplemented collision used" << std::endl;
	return false;
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

bool Robot::get_visibility() const
{
	return time_visible == 0;
}

void Robot::set_x_coordinate(int p_x)
{
	m_position.x = p_x;
}

int Robot::get_x_coordinate() const
{
	return m_position.x;
}

void Robot::set_y_coordinate(int p_y)
{
	m_position.y = p_y;
}

int Robot::get_y_coordinate() const
{
	return m_position.y;
}

RobotType Robot::get_robot_type() const
{
	return m_robot_type;
}

void Robot::update_position(Point2D p_new_position)
{
	m_position = p_new_position;
}

Point2D Robot::get_position() const
{
	return m_position;
}

void Robot::reset_robot()
{
	// reset the robot's coordinates
	m_position = m_position_backup;

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

