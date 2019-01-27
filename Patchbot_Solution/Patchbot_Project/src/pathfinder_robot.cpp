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
	if (check_reachable())
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
		if (check_reachable() && check_line_of_sight())
		{
			//move_towards_patchbot();
		}
		else
		{
			m_ai_state = PathfinderState::WAITING;
		}
		break;

	case HUNTER:
		if (check_reachable() && check_line_of_sight())
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
		if (check_reachable())
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
	if (check_reachable() && check_line_of_sight())
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
	return false;
}

bool PathfinderRobot::check_reachable()
{
	return false;
}

bool PathfinderRobot::check_line_of_sight()
{
	// returning true for debugging purposes and until implementation is
	// complete
	return true;
}
