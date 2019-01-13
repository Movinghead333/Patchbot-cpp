#include "tile.h"

#include "exceptions.h"

Tile::Tile(TileType p_tile_type) : m_tile_type(p_tile_type)
{
};

char Tile::get_source_char(const Tile& input_tile)
{
	char result;
	switch (input_tile.m_tile_type)
	{
		case PATCHBOT_SPAWN: result = 'p'; break;
		case ROOT_SERVER: result = 'P'; break;
		case STEELPLANKS: result = ' '; break;
		case INDESTRUCTABLE_WALL: result = '#'; break;
		case DESTRUCTABLE_WALL: result = 'M'; break;
		case MANUAL_DOOR_CLOSED: result = 'd'; break;
		case AUTO_DOOR_CLOSED: result = 'D'; break;
		case ALIEN_GRASS: result = 'g'; break;
		case GRAVEL: result = '.'; break;
		case SECRET_ENTRANCE: result = 'x'; break;
		case ABYSS: result = 'o'; break;
		case WATER: result = '~'; break;
		default: throw Simple_Message_Exception("Input tiletype non existent!");
	}
	return result;
}

TileType Tile::get_tile_type() const
{
	return m_tile_type;
}

void Tile::set_m_tile_type(TileType p_tile_type)
{
	m_tile_type = p_tile_type;
}

void Tile::set_m_best_direction(BestPath p_new_direction)
{
	m_best_direction = p_new_direction;
}

BestPath Tile::get_m_best_direction() const
{
	return m_best_direction;
}
