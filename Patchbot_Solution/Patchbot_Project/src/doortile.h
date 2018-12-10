#ifndef __DOOR_TILE_H_DEFINED__
#define __DOOR_TILE_H_DEFINED__

#include "tile.h"

class DoorTile : public Tile
{
public:
	// basic constructor inheriting from parent class
	DoorTile(bool p_is_manual, TileType p_tile_type) : Tile(p_tile_type) {};

	bool is_manual_door() const;
	bool is_open();

	void set_door_status(bool p_status);

private:
	bool m_is_manual_door;
	bool m_is_open;
};

#endif