#include "door.h"

Door::Door(int p_x, int p_y) :
	m_x(p_x),
	m_y(p_y),
	m_open_timer(0)
{
}

void Door::update(int p_patchbot_x, int p_patchbot_y, Tile& p_door_tile)
{
 	if (m_open_timer != 0)
	{
		m_open_timer--;
	}

	// check if a door timer has ticked down if so change the door back to 
		// closed
	if (m_open_timer == 0)
	{
		// close the door
		if (p_door_tile.get_tile_type() == TileType::MANUAL_DOOR_OPEN)
		{
			if (p_patchbot_x == m_x && p_patchbot_y == m_y)
			{
				return;
			}
			p_door_tile.set_m_tile_type(TileType::MANUAL_DOOR_CLOSED);
		}
		else if (p_door_tile.get_tile_type() == TileType::AUTO_DOOR_OPEN)
		{
			if (p_patchbot_x == m_x && p_patchbot_y == m_y)
			{
				return;
			}
			p_door_tile.set_m_tile_type(TileType::AUTO_DOOR_CLOSED);
		}
	}

	if (p_patchbot_x == m_x && p_patchbot_y == m_y)
	{
		if (p_door_tile.get_tile_type() == TileType::MANUAL_DOOR_CLOSED)
		{
			m_open_timer = 10;
			p_door_tile.set_m_tile_type(TileType::MANUAL_DOOR_OPEN);
		}
	}
}

void Door::reset(Tile& p_door_tile)
{
	if (m_open_timer != 0)
	{
		m_open_timer = 0;
		if (p_door_tile.get_tile_type() == TileType::MANUAL_DOOR_OPEN)
		{
			p_door_tile.set_m_tile_type(TileType::MANUAL_DOOR_CLOSED);
		}
		else if (p_door_tile.get_tile_type() == TileType::AUTO_DOOR_OPEN)
		{
			p_door_tile.set_m_tile_type(TileType::AUTO_DOOR_CLOSED);
		}
	}
}
;