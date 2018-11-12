#ifndef __UTILITY_H_DEFINED__
#define __UTILITY_H_DEFINED__

#include <string>
#include <sstream>

#include "tile_type.h"
#include "tile.h"
#include "exceptions.h"

// class containing utility methods which do not have a specific context
class Utility
{
public:
	// checks wether a string can be converted to a number
	static const bool is_number(const std::string& s);

	// return the TileType for a given input char parameter if the char is not
	// a valid input it throws an Simple_Message_Exception stating the unknown
	// char
	static const TileType char_to_tile_type(const char& input_char);
};

#endif
