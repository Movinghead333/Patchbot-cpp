#include "ai_controller.h"

// default constructor
AIController::AIController()
{
}

// receives a std::shared_ptr<Robot> and updates the corresponding robot
void AIController::update_ai(std::shared_ptr<Robot>& p_robot)
{
	switch (p_robot->get_robot_type())
	{
	// update all Buggers
	case RobotType::BUGGER:
		update_bugger(p_robot);
		
		break;
	
	// update all LineRobots
	case RobotType::PUSHER:
	case RobotType::DIGGER:
	case RobotType::SWIMMER:
		update_line_robot(p_robot);
		break;

	// update all PathfinderRobots
	case RobotType::FOLLOWER:
	case RobotType::HUNTER:
	case RobotType::SNIFFER:
		update_pathfinder_robot(p_robot);
		break;

	// patchbot needs no ai update
	case RobotType::PATCHBOT:
		return;

	case RobotType::DEAD:
		p_robot->update_visible_time();
		break;
	}
}

// methods for the bugger AI
void AIController::update_bugger(std::shared_ptr<Robot>& p_robot)
{
	// get a reference to the bugger subclass to access Bugger related data
	Bugger& bugger = static_cast<Bugger&>(*p_robot);


	// perfom the next action based on the current AI state
	switch (bugger.get_m_ai_state())
	{
	case BuggerStates::FIND_ANOTHER_WALL:
		check_find_another_wall(bugger);
		break;

	case BuggerStates::FOLLOW_WALL:
		check_follow_wall(bugger);
		break;

	case BuggerStates::PATH_BLOCKED:
		check_wait(bugger);
		break;

	}
}

void AIController::check_find_another_wall(Bugger& bugger)
{
	// get target direction
	BuggerDirections new_dir = Utility::get_next_direction(
		Utility::get_next_direction(bugger.get_m_current_wall()));

	// get target position
	Point2D targetpos = bugger.get_target_position(new_dir);

	if (Utility::check_boundries(targetpos, m_colony->get_width(),
		m_colony->get_height()))
	{
		// get target Tile&
		Tile& target_tile = m_colony->get_editable_tile_ref_by_coordiantes(
			targetpos);

		// check collision
		if (bugger.check_collision(target_tile))
		{
			if (!target_tile.get_occupied())
			{
				m_colony->move_robot_on_map(bugger, targetpos);
			}
		}
		else
		{
			// now follow it
			bugger.set_m_ai_state(BuggerStates::FOLLOW_WALL);
			bugger.set_m_current_wall(new_dir);
			bugger.set_starting_position(targetpos);
		}
	}
}

void AIController::check_follow_wall(Bugger& bugger)
{
	// get target direction
	BuggerDirections new_dir =
		Utility::get_next_direction(bugger.get_m_current_wall());

	// get target position
	Point2D targetpos = bugger.get_target_position(new_dir);

	// check if the bugger is at its starting location
	// if so send it to find another wall
	// else try to follow the wall
	if (bugger.check_for_starting_position(targetpos))
	{
		// found starting position so search for another wall
		bugger.set_m_ai_state(BuggerStates::FIND_ANOTHER_WALL);
	}
	else
	{
		if (Utility::check_boundries(targetpos, m_colony->get_width(),
			m_colony->get_height()))
		{
			// get target Tile&
			Tile& target_tile = m_colony->get_editable_tile_ref_by_coordiantes(
				targetpos);

			// check collision and if there is no robot on the tile
			if (bugger.check_collision(target_tile))
			{
				// the target is not a wall and there is no robot on it
				if (!target_tile.get_occupied())
				{
					m_colony->move_robot_on_map(bugger, targetpos);
				}
				// the target tile is not a wall but there is a robot on it
				else
				{
					// wait because the target tile is blocked
					bugger.set_m_ai_state(BuggerStates::PATH_BLOCKED);
				}
			}
			// the target tile is a wall
			else
			{
				bugger.set_m_current_wall(
					Utility::get_next_direction(bugger.get_m_current_wall()));
			}
		}
	}
}

void AIController::check_wait(Bugger& bugger)
{
	// get target direction
	BuggerDirections new_dir =
		Utility::get_next_direction(bugger.get_m_current_wall());

	// get target position
	Point2D targetpos = bugger.get_target_position(new_dir);
	if (Utility::check_boundries(targetpos, m_colony->get_width(),
		m_colony->get_height()))
	{
		// get target Tile&
		Tile& target_tile = m_colony->get_editable_tile_ref_by_coordiantes(
			targetpos);

		// check if the target field is free
		if (!target_tile.get_occupied())
		{
			// if the target tile is free again proceed following the wall
			bugger.set_m_ai_state(BuggerStates::FOLLOW_WALL);
		}
	}
}


// methods for LineRobots AI
void AIController::update_line_robot(std::shared_ptr<Robot>& p_robot)
{
	LineRobot& line_robot = static_cast<LineRobot&>(*p_robot);
}


// methods for PathfindingRobots
void AIController::update_pathfinder_robot(std::shared_ptr<Robot>& p_robot)
{
	PathfinderRobot& pathfinder_robot = static_cast<PathfinderRobot&>(*p_robot);
}


// setup the colony pointer
void AIController::set_colony_ptr(std::shared_ptr<Colony> p_colony)
{
	m_colony = p_colony;
}

// check if the colony pointer is setup
bool AIController::is_setup()
{
	return m_colony != nullptr;
}
