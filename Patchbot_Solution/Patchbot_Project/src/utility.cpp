#include "utility.h"

 bool Utility::is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

TileType Utility::char_to_tile_type(const char& input_char)
{
	TileType temp_tile_type;
	switch (input_char)
	{
	case 'p': temp_tile_type = PATCHBOT_SPAWN; break;
	case 'P': temp_tile_type = ROOT_SERVER; break;
	case ' ': temp_tile_type = STEELPLANKS; break;
	case '#': temp_tile_type = INDESTRUCTABLE_WALL; break;
	case 'M': temp_tile_type = DESTRUCTABLE_WALL; break;
	case 'd': temp_tile_type = MANUAL_DOOR; break;
	case 'D': temp_tile_type = AUTO_DOOR; break;
	case 'g': temp_tile_type = ALIEN_GRASS; break;
	case '.': temp_tile_type = GRAVEL; break;
	case 'x': temp_tile_type = SECRET_ENTRANCE; break;
	case 'O': temp_tile_type = ABYSS; break;
	case '~': temp_tile_type = WATER; break;
	default:
		std::stringstream temp_string_stream;
		temp_string_stream << "Unknown Character found: " << input_char;
		throw Simple_Message_Exception(temp_string_stream.str());

	}
	return temp_tile_type;
}
