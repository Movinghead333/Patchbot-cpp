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

	//
	void change_door_texture_to_open();
	
	// returns the char, from which the input tile-object was created
	static char get_source_char(const Tile& input_tile);

	// getter member field m_tile_type
	TileType get_tile_type() const;

	void set_m_tile_type(TileType p_tile_type);

	void set_robot_id_back_up(int p_robot_id_backup);

	void set_m_best_path(BestPath p_new_direction);
	BestPath get_m_best_path() const;

	void set_robot_id(int p_robot_id);
	int get_robot_id() const;

	void set_pathing_done(bool p_pathing_done);
	bool get_pathing_done() const;

	// returns true if the tile is blocked by a robot
	bool get_occupied() const;

	
protected:
	// stores the type of a given tile for later comparisons in game
	TileType m_tile_type;
	BestPath m_best_path;

	// stores the id of the robot that is on this tile
	// if there is no robot on this tile the id is -1
	int m_robot_id;

	// back up robot id for map reset
	int m_robot_id_backup;

	// indicates if tiles has been check by dijkstra algorithm
	bool m_pathing_done = false;
};

#endif
