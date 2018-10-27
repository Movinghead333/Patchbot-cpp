#include "tile.h"
#include "exceptions.h"

Tile::Tile(TileType p_tile_type) : m_tile_type(p_tile_type)
{
};

Tile::Tile(const char& char_input)
{
	switch (char_input)
	{
	case 'p': m_tile_type = PATCHBOT_SPAWN; break;
	case 'P': m_tile_type = ROOT_SERVER; break;
	case ' ': m_tile_type = STEELPLANKS; break;
	case '#': m_tile_type = INDESTRUCTABLE_WALL; break;
	case 'M': m_tile_type = DESTRUCTABLE_WALL; break;
	case 'd': m_tile_type = MANUAL_DOOR; break;
	case 'D': m_tile_type = AUTO_DOOR; break;
	case 'g': m_tile_type = ALIEN_GRASS; break;
	case '.': m_tile_type = GRAVEL; break;
	case 'x': m_tile_type = SECRET_ENTRANCE; break;
	case 'o': m_tile_type = ABYSS; break;
	case '~': m_tile_type = WATER; break;
	default: throw "Unknown Character found: " + char_input;

	}

}

char Tile::get_source_char(Tile input_tile)
{
	char result;
	switch (input_tile.m_tile_type)
	{
		case PATCHBOT_SPAWN: result = 'p'; break;
		case ROOT_SERVER: result = 'P'; break;
		case STEELPLANKS: result = ' '; break;
		case INDESTRUCTABLE_WALL: result = '#'; break;
		case DESTRUCTABLE_WALL: result = 'M'; break;
		case MANUAL_DOOR: result = 'd'; break;
		case AUTO_DOOR: result = 'D'; break;
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
