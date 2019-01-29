#ifndef __COLONY_H_DEFINED__
#define __COLONY_H_DEFINED__

#include <string>
#include <vector>
#include <queue>

#include "robot.h"
#include "patchbot.h"
#include "bugger.h"
#include "line_robot.h"
#include "pathfinder_robot.h"
#include "tile.h"
#include "utility.h"
#include "exceptions.h"
#include "door.h"
#include "node.h"

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
		const std::vector<std::shared_ptr<Robot>>& p_enemy_robots, 
		const std::vector<Tile>& p_tiles,
		const std::vector<Door>& p_doors,
		const std::vector<Point2D> p_destroyable_walls);

	// getter- and setter-methods
	int get_width() const;
	int get_height() const;

	const std::vector<Tile>& get_tiles() const;
	const Tile& get_tile_by_coordinates(int x, int y) const;

	void set_tile_type_by_coordinates(int x, int y, TileType p_tile_type);

	// get a ref to the vector storing all the robots from the current colony
	// these getters are no const so the returned references can change the 
	// current colony object
	std::vector<std::shared_ptr<Robot>>& get_robots();
	Patchbot& get_patch_bot();

	std::shared_ptr<Robot>& get_robot_by_id(int p_id);

	// get changable vector of all doors
	std::vector<Door>& get_doors();

	Tile& get_editable_tile_ref_by_coordinates(int p_x, int p_y);

	Tile& get_tile_by_pos(Point2D p_position);


	// static laoding method for creating a colony* for given filename
	static Colony* load_colony(const std::string& file_name);

	// MEMBER METHODS

	// resets the colony to its initial state
	void reset_colony();

	void update_doors();

	// updates the colony's nav mesh for patchbots current position
	// upper complexity boundry:
	// O(colony_width * colony_height * log(colony_width * colony_height))
	void generate_nav_mesh();

	// moves a robot and updates the occupation flags for the involved tiles
	// note that this method does not check if the given position is a valid 
	// move this check has to be performed by the caller
	void move_robot_on_map(Robot& p_robot, Point2D p_target_position);

	// check if a given Point2D is within map boundries
	bool is_in_map_boundries(const Point2D& p_point) const;

	// update tiles to correspond to robot move
	void update_robot_position(Point2D p_old_pos, Point2D p_new_pos);

	// DEBUG-methods
	void print_robot_id_matrix() const;
	void print_occupiation_matrix() const;

private:
	// number of tiles along the x-axis
	const int m_width;

	// number of tiles along the y-axis
	const int m_height;

	// vector storing a Tile-object for each x,y-pair
	std::vector<Tile> m_tiles;

	// vector holding all doors in order to update them while the game is
	// running
	std::vector<Door> m_doors;

	// vector storing all position where destroyable tiles are located
	std::vector<Point2D> m_destroyable_walls;

	// vector storing all robots
	// and their properties (e.g. x and y coordiante)
	// stores the player in its last element
	std::vector<std::shared_ptr<Robot>> m_robots;


};

#endif

