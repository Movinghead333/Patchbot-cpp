#include "patchbot.h"
#include "colony.h"

bool Patchbot::check_collision(Tile & p_target_tile)
{
	switch (p_target_tile.get_tile_type())
	{
	// no collision
	case TileType::SECRET_ENTRANCE:
	case TileType::GRAVEL:
	case TileType::AUTO_DOOR_OPEN:
	case TileType::PATCHBOT_SPAWN:
	case TileType::ENEMY_SPAWN:
	case TileType::STEELPLANKS:
	case TileType::MANUAL_DOOR_OPEN:
	case TileType::ALIEN_GRASS:
		return false;
	case TileType::ABYSS:
		//set_game_state(GameState::FELL_INTO_ABYSS);
		return false;
	case TileType::WATER:
		//set_game_state(GameState::FELL_INTO_WATER);
		return false;

	// collision
		
	case TileType::ROOT_SERVER:
		// no need to check the wincondition because patch has to move to the
		// tile and not be pushed onto it
		// check should be done by controller

		//set_game_state(GameState::SERVER_REACHED);
		return true;
	case TileType::INDESTRUCTABLE_WALL:
	case TileType::DESTRUCTABLE_WALL:
	case TileType::AUTO_DOOR_CLOSED:
		return true;
	case TileType::MANUAL_DOOR_CLOSED:
		// code commented because pushing a robot into a door means the robot
		// did not open it itself so no action required

		//m_current_colony->get_editable_tile_ref_by_coordinates(x, y).
		//	set_m_tile_type(TileType::MANUAL_DOOR_OPEN);
		//TODO: decide wether a door takes one or 2 moves
		//m_current_move.m_steps++;
		return true;

	default: return false;
	}
}
