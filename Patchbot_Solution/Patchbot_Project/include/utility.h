#ifndef __UTILITY_H_DEFINED__
#define __UTILITY_H_DEFINED__

#include <string>
#include <sstream>

#include "best_path.h"
#include "exceptions.h"
#include "tile.h"
#include "tile_type.h"

// class containing utility methods which do not have a specific context
class Utility
{
public:
	// checks wether a string can be converted to a number
	static bool is_number(const std::string& s);

	// return the TileType for a given input char parameter if the char is not
	// a valid input it throws an Simple_Message_Exception stating the unknown
	// char
	static TileType char_to_tile_type(const char& input_char);

	static BestPath char_to_nav_mesh_value(const char& input_char);

	static int get_distance_from_tile_Type(TileType p_tile_type);
};

#endif
