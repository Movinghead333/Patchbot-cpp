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
			//move_towards_patchbot();
		}
		else
		{
			m_ai_state = PathfinderState::WAITING;
		}
		break;

	case HUNTER:
		if (check_reachable(p_colony) && check_line_of_sight())
		{
			//move_towards_patchbot();
			//move_towards_patchbot();
		}
		else
		{
			m_ai_state = PathfinderState::HUNTING;
		}
		break;
	case SNIFFER:
		if (check_reachable(p_colony))
		{
			//move_towards_patchbot();
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
		//move_to_last_known_location();
		//move_to_last_known_location();
	}
}

bool PathfinderRobot::check_collision(Tile & p_target_tile)
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
	BestPath next_dir = p_colony.get_tile_by_pos(m_position).get_m_best_path;
	return next_dir != BestPath::TARGET ||
		   next_dir != BestPath::UNREACHABLE ||
		   next_dir != BestPath::UNSET;
} 

bool PathfinderRobot::check_line_of_sight()
{
	// returning true for debugging purposes and until implementation is
	// complete
	return true;
}
