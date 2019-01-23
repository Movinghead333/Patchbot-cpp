#include "door.h"

Door::Door(int p_x, int p_y) :
	m_x(p_x),
	m_y(p_y),
	m_open_timer(-1)
{
}

void Door::update(Tile& p_door_tile)
{
 	if (m_open_timer > 0)
	{
		m_open_timer--;
	}

	TileType door_tile_type = p_door_tile.get_tile_type();

	// check if a door timer has ticked down if so change the door back to 
		// closed
	if (m_open_timer == 0)
	{
		// close the door
		if (door_tile_type == TileType::MANUAL_DOOR_OPEN)
		{
			if (p_door_tile.get_occupied())
			{
				return;
			}
			p_door_tile.set_m_tile_type(TileType::MANUAL_DOOR_CLOSED);
			m_open_timer = -1;
		}
		else if (door_tile_type == TileType::AUTO_DOOR_OPEN)
		{
			if (p_door_tile.get_occupied())
			{
				return;
			}
			p_door_tile.set_m_tile_type(TileType::AUTO_DOOR_CLOSED);
			m_open_timer = -1;
		}
	}

	if (m_open_timer == -1)
	{
		if (door_tile_type == TileType::MANUAL_DOOR_OPEN ||
			door_tile_type == TileType::AUTO_DOOR_OPEN)
		{
			m_open_timer = 10;
		}
	}
}

void Door::reset()
{
	m_open_timer = -1;	
}
;