#ifndef __COLONY_H_DEFINED__
#define __COLONY_H_DEFINED__

#include <string>
#include <vector>
#include "robot.h"
#include "tile.h"
#include "utility.h"
#include "exceptions.h"

class Colony
{
public:
	//

	Colony(const int p_width, const int p_height,
		   Robot* p_patchbot, std::vector<Robot> p_enemy_robots, const std::vector<Tile> p_tiles);

	const Tile get_tile_by_coordinates(const int& x, const int& y) const;

	const int get_width() const;

	const int get_height() const;

	const std::vector<Robot> get_enemy_robots() const;

	const std::vector<Tile>& get_tiles() const;

	const Robot* get_patch_bot() const;

	static Colony* load_colony(const std::string& file_name);

private:
	const int m_width;
	const int m_height;
	const std::vector<Tile> m_tiles;
	std::vector<Robot> m_enemy_robots;
	Robot* m_patchbot;
};

#endif

