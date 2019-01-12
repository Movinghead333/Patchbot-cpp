#ifndef __TILE_H_DEFINED__
#define __TILE_H_DEFINED__

#include "tile_type.h"
#include "best_direction.h"

// base class for storing the different tiles in the game
class Tile
{
public:
	// constructor receiving a TileType for creating a new tile
	Tile(TileType p_tile_type);
	
	// returns the char, from which the input tile-object was created
	static char get_source_char(const Tile& input_tile);

	// getter member field m_tile_type
	TileType get_tile_type() const;

	void set_m_tile_type(TileType p_tile_type);

	void set_m_best_direction(BestDirection p_new_direction);
	BestDirection get_m_best_direction() const;

	
protected:
	// stores the type of a given tile for later comparisons in game
	TileType m_tile_type;
	BestDirection m_best_direction;
};

#endif
