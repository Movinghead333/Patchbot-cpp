#include "tile.h"

#include "exceptions.h"

Tile::Tile(
	TileType p_tile_type,
	BestPath p_nav_mesh_value,
	int p_robot_id)
	:
	m_tile_type(p_tile_type),
	m_best_path(p_nav_mesh_value),
	m_robot_id(p_robot_id),
	m_robot_id_backup(p_robot_id)
{
}
void Tile::reset()
{
	m_robot_id = m_robot_id_backup;

	if (m_tile_type == TileType::MANUAL_DOOR_OPEN)
	{
		m_tile_type = TileType::MANUAL_DOOR_CLOSED;
	}
	else if (m_tile_type == TileType::AUTO_DOOR_OPEN)
	{
		m_tile_type = TileType::AUTO_DOOR_OPEN;
	}
}
void Tile::change_door_texture_to_open()
{
	if (m_tile_type == TileType::MANUAL_DOOR_CLOSED)
	{
		m_tile_type = TileType::MANUAL_DOOR_OPEN;
	}

	if (m_tile_type == TileType::AUTO_DOOR_CLOSED)
	{
		m_tile_type = TileType::AUTO_DOOR_OPEN;
	}
}
;

char Tile::get_source_char(const Tile& input_tile)
{
	char result;
	switch (input_tile.m_tile_type)
	{
		case TileType::PATCHBOT_SPAWN:		result = 'p'; break;
		case TileType::ROOT_SERVER:			result = 'P'; break;
		case TileType::STEELPLANKS:			result = ' '; break;
		case TileType::INDESTRUCTABLE_WALL: result = '#'; break;
		case TileType::DESTRUCTABLE_WALL:	result = 'M'; break;
		case TileType::MANUAL_DOOR_CLOSED:  result = 'd'; break;
		case TileType::AUTO_DOOR_CLOSED:	result = 'D'; break;
		case TileType::ALIEN_GRASS:			result = 'g'; break;
		case TileType::GRAVEL:				result = '.'; break;
		case TileType::SECRET_ENTRANCE:		result = 'x'; break;
		case TileType::ABYSS:				result = 'o'; break;
		case TileType::WATER:				result = '~'; break;
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

void Tile::set_robot_id_back_up(int p_robot_id_backup)
{
	m_robot_id_backup = p_robot_id_backup;
}

void Tile::set_m_best_path(BestPath p_new_direction)
{
	m_best_path = p_new_direction;
}

BestPath Tile::get_m_best_path() const
{
	return m_best_path;
}

void Tile::set_robot_id(int p_robot_id)
{
	 m_robot_id = p_robot_id;
}

int Tile::get_robot_id() const
{
	return m_robot_id;
}

bool Tile::get_occupied() const
{
	return m_robot_id != -1;
}
