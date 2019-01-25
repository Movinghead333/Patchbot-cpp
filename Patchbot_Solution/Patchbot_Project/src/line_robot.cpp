#include "line_robot.h"
#include "colony.h"

void LineRobot::update(Colony& p_colony)
{
	std::cout << "line robot updated!" << std::endl;
	switch (m_ai_state)
	{
	case X_MOVEMENT:
		update_x_movement(p_colony);
		break;
	case Y_MOVEMENT:
		update_y_movement(p_colony);
		break;
	case DESTROYED:
		return;
	}
}

void LineRobot::reset_robot()
{
	Robot::reset_robot();
	m_ai_state = LineRobotState::X_MOVEMENT;
}

bool LineRobot::check_collision(Tile& p_target_tile)
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
		if (m_robot_type == RobotType::SWIMMER)
		{
			return false;
		}
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

void LineRobot::update_x_movement(Colony& p_colony)
{
	// get patchbot's current x
	int patchbot_x = p_colony.get_patch_bot().get_x_coordinate();
	// check if the x coordinate already matches patchbot's
	if (m_position.x == patchbot_x)
	{
		m_ai_state = LineRobotState::Y_MOVEMENT;
		return;
	}

	// since the x coordinates don't match calculate the next position
	int target_x = m_position.x;
	if (target_x > patchbot_x)
	{
		target_x--;
	}
	else
	{
		target_x++;
	}

	Point2D target_pos = Point2D(target_x, m_position.y);

	// reference to the target tile
	// no need to check wether it is within the map boundries since the pusher
	// can only be as far as patchbot
	Tile& target_tile = p_colony.get_editable_tile_ref_by_coordinates(
		target_pos);

	// the current tile is a wall
	if (check_collision(target_tile))
	{
		m_ai_state = LineRobotState::Y_MOVEMENT;
		return;
	}
	// the current tile is not a wall
	else
	{
		// target tile is blocked by a robot
		if (target_tile.get_occupied())
		{
			// set the enemeis target x based on the robots position relative
			// to patchbot
			int enemy_target_x = target_x;
			if (m_position.x > patchbot_x)
			{
				enemy_target_x--;
			}
			else
			{
				enemy_target_x++;
			}

			// check if the enemy target_pos is inside the map
			Point2D enemy_target_pos = Point2D(enemy_target_x, m_position.y);
			if (p_colony.is_in_map_boundries(enemy_target_pos))
			{
				std::cout << "preparing for push" << std::endl;
				Tile& enemy_target_tile = p_colony.
					get_editable_tile_ref_by_coordinates(enemy_target_pos);

				int enemy_robot_id = target_tile.get_robot_id();

				std::shared_ptr<Robot>& enemy_robot = p_colony.
					get_robot_by_id(enemy_robot_id);

				// check if the tile where the other robot should be move to is
				// neither a wall nor another robot
				if (!enemy_target_tile.get_occupied() &&
					!enemy_robot->check_collision(enemy_target_tile))
				{
					// move the other robot first
					p_colony.update_robot_position(target_pos, enemy_target_pos);
					enemy_robot->update_position(enemy_target_pos);

					// move the LineRobot
					p_colony.update_robot_position(m_position, target_pos);
					set_x_coordinate(target_x);
				}
				else
				{
					m_ai_state = LineRobotState::Y_MOVEMENT;
					return;
				}
			}
		}
		// target tile is free
		else
		{
			p_colony.update_robot_position(m_position, target_pos);
			set_x_coordinate(target_x);
		}
	}

	// check if the RobotType has been set to DEAD if so change state to
	// destroyed
	if (m_robot_type == RobotType::DEAD)
	{
		m_ai_state = LineRobotState::DESTROYED;
	}

}

void LineRobot::update_y_movement(Colony& p_colony)
{
}
