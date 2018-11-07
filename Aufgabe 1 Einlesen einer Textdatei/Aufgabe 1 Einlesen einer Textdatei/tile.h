#ifndef __TILE_H_DEFINED__
#define __TILE_H_DEFINED__

#include "tile_type.h"

// base class for storing the different tiles in the game
class Tile
{
public:
	// constructor receiving a TileType for creating a new tile
	Tile(const TileType p_tile_type);
	
	// returns the char, from which the input tile-object was created
	const static char get_source_char(const Tile input_tile);

	// getter member field m_tile_type
	const TileType get_tile_type() const;

private:
	// stores the type of a given tile for later comparisons in game
	const TileType m_tile_type;
};

#endif
