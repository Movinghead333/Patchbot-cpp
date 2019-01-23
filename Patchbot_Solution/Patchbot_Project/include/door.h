#ifndef __DOOR_H_DEFINED__
#define __DOOR_H_DEFINED__

#include "tile.h"

#include <iostream>

struct Door
{
	int m_x;
	int m_y;
	int m_open_timer;

	Door(int p_x, int p_y);

	// updates a door based on patchbots next position and the Tile
	// the door object is referencing to
	void update(Tile& p_door_tile);

	// resets the door object and the corresponding tile object via the 
	// passed reference
	void reset();
};

#endif