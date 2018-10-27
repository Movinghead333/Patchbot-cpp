#ifndef __TILE_H_DEFINED__
#define __TILE_H_DEFINED__

#include "tile_type.h"

class Tile
{
public:
	Tile(TileType p_tile_type);

	Tile(const char& char_input);
	
	static char get_source_char(Tile input_tile);

	TileType get_tile_type() const;

private:
	TileType m_tile_type;
};

#endif
