#ifndef __COLONY_H_DEFINED__
#define __COLONY_H_DEFINED__

#include <string>
#include <vector>

#include "robot.h"
#include "tile.h"
#include "utility.h"
#include "exceptions.h"
#include "doortile.h"

class Colony
{
public:
	// constructor
	// @param width and height of colony, the player instance in form of a robot
	// object, a vector holding all enemy robots and a vector holding all
	// maptiles
	Colony(
		const int p_width,
		const int p_height,
		std::vector<Robot> p_enemy_robots, 
		const std::vector<Tile> p_tiles);

	~Colony();

	// getter-methods
	int get_width() const;
	int get_height() const;

	const std::vector<Tile>& get_tiles() const;
	const Tile& get_tile_by_coordinates(int x, int y) const;

	// get a ref to the vector storing all the robots from the current colony
	std::vector<Robot>& get_robots();
	Robot& get_patch_bot();

	// static laoding method for creating a colony* for given filename
	static Colony* load_colony(const std::string& file_name);

private:
	// number of tiles along the x-axis
	const int m_width;

	// number of tiles along the y-axis
	const int m_height;

	// vector storing a Tile-object for each x,y-pair
	const std::vector<Tile> m_tiles;

	// vector storing all robots
	// and their properties (e.g. x and y coordiante)
	// stores the player in its last element
	std::vector<Robot> m_robots;
};

#endif

