#ifndef __TILE_H_DEFINED__
#define __TILE_H_DEFINED__

#include "tile_type.h"
#include "best_path.h"

// base class for storing the different tiles in the game
class Tile
{
public:
	// constructor receiving a TileType for creating a new tile
	Tile(TileType p_tile_type, BestPath p_nav_mesh_value, int p_robot_id);

	// reset tile
	void reset();
	
	// returns the char, from which the input tile-object was created
	static char get_source_char(const Tile& input_tile);

	// getter member field m_tile_type
	TileType get_tile_type() const;

	void set_m_tile_type(TileType p_tile_type);

	void set_m_best_path(BestPath p_new_direction);
	BestPath get_m_best_path() const;

	void set_robot_id(int p_robot_id);
	int get_robot_id() const;

	bool get_occupied() const;

	
protected:
	// stores the type of a given tile for later comparisons in game
	TileType m_tile_type;
	BestPath m_best_path;

	// stores the id of the robot that is on this tile
	// if there is no robot on this tile the id is -1
	int m_robot_id;

	// back up robot id for map reset
	const int m_robot_id_backup;
};

#endif
