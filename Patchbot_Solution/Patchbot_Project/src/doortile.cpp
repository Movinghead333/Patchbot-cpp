#include "doortile.h"



DoorTile::DoorTile(bool p_is_manual, TileType p_tile_type) :
	m_is_manual_door(p_is_manual),
{
	m_is_open = false;
}

void DoorTile::set_door_status(bool p_status)
{
	m_is_open = p_status;
}
