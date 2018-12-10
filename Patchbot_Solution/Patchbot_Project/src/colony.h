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
		Robot* p_patchbot,
		std::vector<Robot> p_enemy_robots, 
		const std::vector<Tile> p_tiles);

	// getter-methods
	int get_width() const;
	int get_height() const;

	const std::vector<Tile>& get_tiles() const;
	const Tile& get_tile_by_coordinates(int x, int y) const;

	const std::vector<Robot> get_enemy_robots() const;
	const Robot* get_patch_bot() const;

	// static laoding method for creating a colony* for given filename
	static Colony* load_colony(const std::string& file_name);

private:
	// number of tiles along the x-axis
	const int m_width;

	// number of tiles along the y-axis
	const int m_height;

	// vector storing a Tile-object for each x,y-pair
	const std::vector<Tile> m_tiles;

	// vector storing all enemy robots
	// and their properties (e.g. x and y coordiante)
	std::vector<Robot> m_enemy_robots;

	// variable storing patchbot itself for quick and easy access
	Robot* m_patchbot;
};

#endif

