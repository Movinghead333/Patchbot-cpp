#include "patchbot.h"
#include "colony.h"

bool Patchbot::check_collision(Tile & p_target_tile)
{
	switch (p_target_tile.get_tile_type())
	{
		// true cases --> no collision
	case TileType::SECRET_ENTRANCE:
	case TileType::GRAVEL:
	case TileType::AUTO_DOOR_OPEN:
	case TileType::PATCHBOT_SPAWN:
	case TileType::ENEMY_SPAWN:
	case TileType::STEELPLANKS:
	case TileType::MANUAL_DOOR_OPEN:
		return true;
	case TileType::ALIEN_GRASS:
		//m_current_colony->get_patch_bot().set_m_blocked(true);
		return true;
	case TileType::ABYSS:
		//set_game_state(GameState::FELL_INTO_ABYSS);
		return true;
	case TileType::WATER:
		//set_game_state(GameState::FELL_INTO_WATER);
		return true;

		// false cases --> collision
	case TileType::ROOT_SERVER:
		//set_game_state(GameState::SERVER_REACHED);
		return false;
	case TileType::INDESTRUCTABLE_WALL:
	case TileType::DESTRUCTABLE_WALL:
	case TileType::AUTO_DOOR_CLOSED:
		return false;
	case TileType::MANUAL_DOOR_CLOSED:
		//m_current_colony->get_editable_tile_ref_by_coordinates(x, y).
		//	set_m_tile_type(TileType::MANUAL_DOOR_OPEN);
		//TODO: decide wether a door takes one or 2 moves
		//m_current_move.m_steps++;
		return false;

	default: return false;
	}
}
