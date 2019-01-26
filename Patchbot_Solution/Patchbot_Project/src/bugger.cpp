#include "bugger.h"
#include "colony.h"

Bugger::Bugger(Point2D p_position, RobotType p_robot_type)
	:
	Robot(p_position, p_robot_type),
	m_start_position(p_position)
{
}

void Bugger::update(Colony& p_colony)
{
	if (m_blocked)
	{
		m_blocked = false;
	}
	// perfom the next action based on the current AI state
	switch (m_ai_state)
	{
	case BuggerStates::FIND_ANOTHER_WALL:
		check_find_another_wall(p_colony);
		break;

	case BuggerStates::FOLLOW_WALL:
		check_follow_wall(p_colony);
		break;

	case BuggerStates::PATH_BLOCKED:
		check_wait(p_colony);
		break;

	}
	update_visible_time();
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

bool Bugger::check_collision(Tile& p_target_tile)
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
		return false;

	case WATER:
	case ABYSS:
		m_robot_type = RobotType::DEAD;
		setup_visible_time();
		return false;

	case MANUAL_DOOR_CLOSED:
	case AUTO_DOOR_CLOSED:
		m_blocked = true;
		p_target_tile.change_door_texture_to_open();
		return true;

	case ROOT_SERVER:
	case SECRET_ENTRANCE:
	case INDESTRUCTABLE_WALL:
	case DESTRUCTABLE_WALL:
		return true;
	}
}

Point2D Bugger::get_target_position(BuggerDirections p_direction)
{
	switch (p_direction)
	{
	case NORTH:
		return Point2D(m_position.x, m_position.y - 1);
		break;
	case EAST:
		return Point2D(m_position.x + 1, m_position.y);
		break;
	case SOUTH:
		return Point2D(m_position.x, m_position.y + 1);
		break;
	case WEST:
		return Point2D(m_position.x - 1, m_position.y);
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

BuggerDirections Bugger::get_next_direction(BuggerDirections p_direction)
{
	switch (p_direction)
	{
	case NORTH:
		return BuggerDirections::EAST;
		break;
	case EAST:
		return BuggerDirections::SOUTH;
		break;
	case SOUTH:
		return BuggerDirections::WEST;
		break;
	case WEST:
		return BuggerDirections::NORTH;
		break;
	}
}

void Bugger::check_find_another_wall(Colony& p_colony)
{
	// get target direction
	BuggerDirections new_dir = get_next_direction(
		get_next_direction(m_current_wall));

	// get target position
	Point2D targetpos = get_target_position(new_dir);

	if (Utility::check_boundries(targetpos, p_colony.get_width(),
		p_colony.get_height()))
	{
		// get target Tile&
		Tile& target_tile = p_colony.get_tile_by_pos(
			targetpos);

		// check collision
		if (!check_collision(target_tile))
		{
			if (!target_tile.get_occupied())
			{
				p_colony.update_robot_position(m_position, targetpos);
				update_position(targetpos);
			}
		}
		else if (!m_blocked)
		{
			// now follow it
			m_ai_state=  BuggerStates::FOLLOW_WALL;
			m_current_wall = new_dir;
			m_start_position = targetpos;
		}
	}
}

void Bugger::check_follow_wall(Colony & p_colony)
{
	// get target direction
	BuggerDirections new_dir = get_next_direction(m_current_wall);

	// get target position
	Point2D targetpos = get_target_position(new_dir);

	// check if the bugger is at its starting location
	// if so send it to find another wall
	// else try to follow the wall
	if (check_for_starting_position(targetpos))
	{
		// found starting position so search for another wall
		m_ai_state = BuggerStates::FIND_ANOTHER_WALL;
	}
	else
	{
		if (Utility::check_boundries(targetpos, p_colony.get_width(),
			p_colony.get_height()))
		{
			// get target Tile&
			Tile& target_tile = p_colony.get_tile_by_pos(
				targetpos);

			// check collision and if there is no robot on the tile
			if (!check_collision(target_tile))
			{
				// the target is not a wall and there is no robot on it
				if (!target_tile.get_occupied())
				{
					p_colony.update_robot_position(m_position, targetpos);
					update_position(targetpos);
				}
				// the target tile is not a wall but there is a robot on it
				else
				{
					// wait because the target tile is blocked
					m_ai_state = BuggerStates::PATH_BLOCKED;
				}
			}
			// the target tile is a wall
			else if (!m_blocked)
			{
				m_current_wall = get_next_direction(m_current_wall);
			}
		}
	}
}

void Bugger::check_wait(Colony & p_colony)
{
	// get target direction
	BuggerDirections new_dir = get_next_direction(m_current_wall);

	// get target position
	Point2D targetpos = get_target_position(new_dir);
	if (Utility::check_boundries(targetpos, p_colony.get_width(),
		p_colony.get_height()))
	{
		// get target Tile&
		Tile& target_tile = p_colony.get_tile_by_pos(
			targetpos);

		// check if the target field is free
		if (!target_tile.get_occupied())
		{
			// if the target tile is free again proceed following the wall
			m_ai_state = BuggerStates::FOLLOW_WALL;
		}
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
