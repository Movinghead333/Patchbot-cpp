#include "pathfinder_robot.h"
#include "colony.h"

void PathfinderRobot::update(Colony& p_colony)
{

	std::cout << "pathfinder robot updated!" << std::endl;
	switch (m_ai_state)
	{
	case WAITING:
		check_waiting(p_colony);
		break;
	case FOLLOWING:
		check_following(p_colony);
		break;
	case HUNTING:
		check_hunting(p_colony);
		break;
	}
}

void PathfinderRobot::check_waiting(Colony& p_colony)
{
	if (check_reachable(p_colony))
	{
		std::cout << "start following" << std::endl;
		if (m_robot_type == RobotType::SNIFFER)
		{
			m_ai_state = PathfinderState::FOLLOWING;
			return;
		}
		else if (check_line_of_sight())
		{
			if (m_robot_type == RobotType::HUNTER)
			{
				m_patchbot_pos = p_colony.get_patch_bot().get_position();
			}
			m_ai_state = PathfinderState::FOLLOWING;
		}
	}
}

void PathfinderRobot::check_following(Colony& p_colony)
{
	switch (m_robot_type)
	{
	case FOLLOWER:
		if (check_reachable(p_colony) && check_line_of_sight())
		{
			move_on_best_path(p_colony);
		}
		else
		{
			m_ai_state = PathfinderState::WAITING;
		}
		break;

	case HUNTER:
		if (check_reachable(p_colony) && check_line_of_sight())
		{
			move_on_best_path(p_colony);
			move_on_best_path(p_colony);
		}
		else
		{
			m_ai_state = PathfinderState::HUNTING;
		}
		break;
	case SNIFFER:
		if (check_reachable(p_colony))
		{
			move_on_best_path(p_colony);
		}
		else
		{
			m_ai_state = PathfinderState::WAITING;
		}
		break;
	}
}

void PathfinderRobot::check_hunting(Colony& p_colony)
{
	if (check_reachable(p_colony) && check_line_of_sight())
	{
		m_patchbot_pos = p_colony.get_patch_bot().get_position();
		m_ai_state = PathfinderState::FOLLOWING;
	}
	else
	{
		move_to_last_known_location(p_colony);
		move_to_last_known_location(p_colony);
	}
}

bool PathfinderRobot::check_collision(Tile& p_target_tile)
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

bool PathfinderRobot::check_reachable(Colony& p_colony)
{
	BestPath next_dir = p_colony.get_tile_by_pos(m_position).get_m_best_path();
	std::cout << "nav_value: " << next_dir << std::endl;
	return next_dir != BestPath::TARGET &&
		   next_dir != BestPath::UNREACHABLE &&
		   next_dir != BestPath::UNSET;
} 

bool PathfinderRobot::check_line_of_sight()
{
	// returning true for debugging purposes and until implementation is
	// complete
	return true;
}

void PathfinderRobot::move_on_best_path(Colony& p_colony)
{
	std::cout << "pathfinder trying to move" << std::endl;
	Point2D target_pos = m_position;

	const Tile& current_tile = p_colony.get_tile_by_pos(m_position);

	switch (current_tile.get_m_best_path())
	{
	case PATH_UP:
		target_pos.y--;
		break;
	case PATH_RIGHT:
		target_pos.x++;
		break;
	case PATH_DOWN:
		target_pos.y++;
		break;
	case PATH_LEFT:
		target_pos.x--;
		break;
	case UNSET:
	case UNREACHABLE:
	case TARGET:
	default:
		return;
	}

	Tile& target_tile = p_colony.get_tile_by_pos(target_pos);

	// check if the target tile is no wall and not currently occupied
	if (!check_collision(target_tile) && !target_tile.get_occupied())
	{
		p_colony.update_robot_position(m_position, target_pos);

	}
}

void PathfinderRobot::move_to_last_known_location(Colony & p_colony)
{
	if (m_position == m_patchbot_pos)
	{
		move_on_best_path(p_colony);
	}
}
