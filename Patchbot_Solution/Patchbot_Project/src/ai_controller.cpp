#include "ai_controller.h"

AIController::AIController()
{
}

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
	}
}

void AIController::set_colony_ptr(std::shared_ptr<Colony> p_colony)
{
	m_colony = p_colony;
}

bool AIController::is_setup()
{
	return m_colony != nullptr;
}

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
			targetpos.x, targetpos.y);

		// check collision
		if (bugger.check_collision(target_tile))
		{
			if (!target_tile.get_occupied())
			{
				// change occupation
				Tile& old_tile = m_colony->get_editable_tile_ref_by_coordiantes(
					bugger.get_x_coordinate(), bugger.get_y_coordinate());

				Colony::change_occupation(old_tile, target_tile);

				// move to tile if it is free
				bugger.set_coordinates(targetpos);
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
		bugger.set_m_ai_state(BuggerStates::FIND_ANOTHER_WALL);
	}
	else
	{
		if (Utility::check_boundries(targetpos, m_colony->get_width(),
			m_colony->get_height()))
		{
			// get target Tile&
			Tile& target_tile = m_colony->get_editable_tile_ref_by_coordiantes(
				targetpos.x, targetpos.y);

			// check collision and if there is no robot on the tile
			if (bugger.check_collision(target_tile))
			{
				// the target is not a wall and there is no robot on it
				if (!target_tile.get_occupied())
				{
					// change occupation
					Tile& old_tile = m_colony->get_editable_tile_ref_by_coordiantes(
						bugger.get_x_coordinate(), bugger.get_y_coordinate());

					Colony::change_occupation(old_tile, target_tile);

					// move to free tile
					bugger.set_coordinates(targetpos);
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
			targetpos.x, targetpos.y);

		// check if the target field is free
		if (!target_tile.get_occupied())
		{
			bugger.set_m_ai_state(BuggerStates::FOLLOW_WALL);
		}
	}
	
}

void AIController::update_line_robot(std::shared_ptr<Robot>& p_robot)
{
	LineRobot& line_robot = static_cast<LineRobot&>(*p_robot);
}

void AIController::update_pathfinder_robot(std::shared_ptr<Robot>& p_robot)
{
	PathfinderRobot& pathfinder_robot = static_cast<PathfinderRobot&>(*p_robot);
}

