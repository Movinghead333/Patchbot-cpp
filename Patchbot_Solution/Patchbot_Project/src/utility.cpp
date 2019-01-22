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
	case 'd': temp_tile_type = MANUAL_DOOR_CLOSED; break;
	case 'D': temp_tile_type = AUTO_DOOR_CLOSED; break;
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

BestPath Utility::char_to_nav_mesh_value(const char & input_char)
{
	BestPath nav_mesh_value;
	switch (input_char)
	{
	case 'p': 
	case 'g': 
	case '.': 
	case ' ':
	case 'd':
	case 'D':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		return BestPath::UNSET;

	case 'P':
	case '#':
	case 'M':
	case 'O':
	case '~':
	case 'x':
		return BestPath::UNREACHABLE;

	default:
		std::stringstream temp_string_stream;
		temp_string_stream << "Unknown Character found: " << input_char;
		throw Simple_Message_Exception(temp_string_stream.str());

	}
}

int Utility::get_distance_from_tile_Type(TileType p_tile_type)
{
	if (p_tile_type == TileType::ALIEN_GRASS ||
		p_tile_type == TileType::AUTO_DOOR_CLOSED ||
		p_tile_type == TileType::MANUAL_DOOR_CLOSED)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

BuggerDirections Utility::get_next_direction(BuggerDirections p_dir)
{
	switch (p_dir)
	{
	case NORTH:
		return BuggerDirections::EAST;
		break;
	case EAST:
		return BuggerDirections::SOUTH;
		break;
	case SOUTH:
		return BuggerDirections::WEST;
		break;
	case WEST:
		return BuggerDirections::NORTH;
		break;
	}
}

bool Utility::check_boundries(int x, int y, int x_limit, int y_limit)
{
	return x >= 0 && x < x_limit && y >= 0 && y < y_limit;
}

bool Utility::check_boundries(Point2D position, int x_limit, int y_limit)
{
	return position.x >= 0 && position.x < x_limit &&
		   position.y >= 0 && position.y < y_limit;
}
