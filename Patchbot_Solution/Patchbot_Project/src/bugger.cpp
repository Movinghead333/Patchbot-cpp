#include "bugger.h"

Bugger::Bugger(Point2D p_position, RobotType p_robot_type)
	:
	Robot(p_position, p_robot_type),
	m_start_position(p_position)
{
}

void Bugger::update()
{
	std::cout << "bugger updated!" << std::endl;
}

void Bugger::reset_robot()
{
	// reset the robots coordinates
	Robot::reset_robot();

	// reset AI startpoint
	m_start_position = m_position_backup;

	// reset inital direction
	m_current_wall = BuggerDirections::NORTH;

	// reset AI state
	m_ai_state = BuggerStates::FOLLOW_WALL;
}

bool Bugger::check_collision(Tile & p_target_tile)
{
	
	switch (p_target_tile.get_tile_type())
	{
	case STEELPLANKS:
	case PATCHBOT_SPAWN:
	case ENEMY_SPAWN:
	case AUTO_DOOR_OPEN:
	case MANUAL_DOOR_OPEN:
	case ALIEN_GRASS:
	case GRAVEL:
		return true;

	case WATER:
	case ABYSS:
		m_robot_type = RobotType::DEAD;
		setup_visible_time();
		return true;

	case ROOT_SERVER:
	case SECRET_ENTRANCE:
	case MANUAL_DOOR_CLOSED:
	case AUTO_DOOR_CLOSED:
	case INDESTRUCTABLE_WALL:
	case DESTRUCTABLE_WALL:
		return false;
	}
}

Point2D Bugger::get_target_position(BuggerDirections p_direction)
{
	switch (p_direction)
	{
	case NORTH:
		return Point2D(m_x_coordinate, m_y_coordinate - 1);
		break;
	case EAST:
		return Point2D(m_x_coordinate + 1, m_y_coordinate);
		break;
	case SOUTH:
		return Point2D(m_x_coordinate, m_y_coordinate + 1);
		break;
	case WEST:
		return Point2D(m_x_coordinate - 1, m_y_coordinate);
		break;
	}
}

bool Bugger::check_for_starting_position(Point2D p_target_point)
{
	if (m_start_position == p_target_point)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Bugger::set_m_current_wall(BuggerDirections p_current_wall)
{
	m_current_wall = p_current_wall;
}

BuggerDirections Bugger::get_m_current_wall() const
{
	return m_current_wall;
}

void Bugger::set_m_ai_state(BuggerStates p_state)
{
	m_ai_state = p_state;
}

BuggerStates Bugger::get_m_ai_state() const
{
	return m_ai_state;
}

void Bugger::set_starting_position(Point2D p_position)
{
	m_start_position = p_position;
}
