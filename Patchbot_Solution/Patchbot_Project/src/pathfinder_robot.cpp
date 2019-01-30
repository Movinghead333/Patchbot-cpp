#include "pathfinder_robot.h"
#include "colony.h"

void PathfinderRobot::update(Colony& p_colony)
{
	// if the robot has been destroyed only update his display time and 
	// when the timer reaches zero reset the occupation of the tile the robot
	// is standing on
	if (m_robot_type == RobotType::DEAD)
	{
		update_visible_time();

		Tile& robot_tile = p_colony.get_tile_by_pos(m_position);

		if (time_visible == 0 && robot_tile.get_occupied())
		{

			robot_tile.set_robot_id(-1);
		}
		return;
	}

	// if the robots has been slowed down by gravel this is true and needs
	// to skip a turn and reset the flag
	if (m_blocked)
	{
		m_blocked = false;
		return;
	}

	// update AI based on its current state
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
	// if patchbot is reachable actions should be taken
	if (check_reachable(p_colony))
	{
		// if the robot is a sniffer the first condition is enough to change
		// the state to following
		if (m_robot_type == RobotType::SNIFFER)
		{
			m_ai_state = PathfinderState::FOLLOWING;
			return;
		}
		// if it a follower or a hunter then line of sight is required
		// also when the current robot is hunter then save patchbot's position
		else if (check_line_of_sight(p_colony))
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
	// code speaks for itself
	switch (m_robot_type)
	{
	case FOLLOWER:
		if (check_reachable(p_colony) && check_line_of_sight(p_colony))
		{
			move_on_best_path(p_colony);
		}
		else
		{
			m_ai_state = PathfinderState::WAITING;
		}
		break;

	case HUNTER:
		if (check_reachable(p_colony) && check_line_of_sight(p_colony))
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
	// if patchbot is reachable through pathfinding and is also in line of 
	// sight of a hunter robot than save patchbot's position and change the
	// state to following
	if (check_reachable(p_colony) && check_line_of_sight(p_colony))
	{
		m_patchbot_pos = p_colony.get_patch_bot().get_position();
		m_ai_state = PathfinderState::FOLLOWING;
	}
	// if the above conditions are not met then move to patchbots last known
	// position
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
		return false;

	case GRAVEL:
		m_blocked = true;
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
	const Tile& robot_tile = p_colony.get_tile_by_pos(m_position);
	std::cout << robot_tile.get_pathing_done() << std::endl;
	
	return robot_tile.get_pathing_done();
} 

//TODO maybe add const and non const patchbot getter
bool PathfinderRobot::check_line_of_sight(Colony& p_colony)
{
	// returning true for debugging purposes and until implementation is
	// complete

	int x1 = m_position.x;
	int y1 = m_position.y;

	const Point2D& patchbot_pos = p_colony.get_patch_bot().get_position();

	int x2 = patchbot_pos.x;
	int y2 = patchbot_pos.y;

	// bresenham algorithm
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;

	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;

	int err = dx + dy;

	while (true)
	{
		if (x1 == x2 && y1 == y2)
		{
			break;
		}

		int e2 = 2 * err;

		if (e2 > dy)
		{
			err += dy;
			x1 += sx;
		}

		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
		
		if (x1 == x2 && y1 == y2)
		{
			return true;
		}

		const Tile& current_tile = p_colony.get_tile_by_coordinates(x1, y1);

		// check if the current tile is blocking line of sight if so
		// immediatly return false
		if (is_line_of_sight_obstacle(current_tile))
		{
			return false;
		}

		std::cout << "next x: " << x1 << " next y: " << y1 << std::endl;
	}
	return true;
}

void PathfinderRobot::move_on_best_path(Colony& p_colony)
{
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

	Patchbot& patchbot = p_colony.get_patch_bot();

	if (target_pos == patchbot.get_position())
	{
		patchbot.set_patchbot_dead();
	}
}

void PathfinderRobot::move_to_last_known_location(Colony & p_colony)
{
	if (m_position == m_patchbot_pos)
	{
		move_on_best_path(p_colony);
	}
}

bool PathfinderRobot::is_line_of_sight_obstacle(const Tile & p_tile) const
{
	if (p_tile.get_occupied())
	{
		return true;
	}
	
	switch (p_tile.get_tile_type())
	{
	case STEELPLANKS:
	case PATCHBOT_SPAWN:
	case ENEMY_SPAWN:
	case ABYSS:
	case WATER:
	case ALIEN_GRASS:
	case GRAVEL:
	case MANUAL_DOOR_OPEN:
	case AUTO_DOOR_OPEN:
		return false;
		break;

	case ROOT_SERVER:
	case SECRET_ENTRANCE:
	case MANUAL_DOOR_CLOSED:
	case AUTO_DOOR_CLOSED:
	case INDESTRUCTABLE_WALL:
	case DESTRUCTABLE_WALL:
		return true;
	}
}
