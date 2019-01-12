#include "colony.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Colony::Colony(
	const int p_width,
	const int p_height,
	const std::vector<Robot>& p_enemy_robots,
	const std::vector<Tile>& p_tiles,
	const std::vector<Door>& p_doors)
	:
	m_width(p_width),
	m_height(p_height),
	m_robots(p_enemy_robots),
	m_tiles(p_tiles),
	m_doors(p_doors)
{
	// TODO: add checks in constructor if necessary
}

// getter methods for member-fields
const Tile& Colony::get_tile_by_coordinates(int x, int y) const
{
	return m_tiles[x + (m_width * y)];
}

void Colony::set_tile_type_by_coordinates(int x, int y, TileType p_tile_type)
{
	m_tiles[x + (m_width * y)].set_m_tile_type(p_tile_type);
}
											
int Colony::get_width() const				
{											
	return m_width;							
}

int Colony::get_height() const
{
	return m_height;
}

const std::vector<Tile>& Colony::get_tiles() const
{
	return m_tiles;
}

 Robot& Colony::get_patch_bot() 
{
	return m_robots[m_robots.size()-1];
}

 std::vector<Door>& Colony::get_doors()
 {
	 return m_doors;
 }

 Tile& Colony::get_editable_tile_ref_by_coordiantes(int p_x, int p_y)
 {
	 return m_tiles[p_x + (m_width * p_y)];
 }

std::vector<Robot>& Colony::get_robots()
{
	return m_robots;
}


// load a colony by filename and return a pointer to the created object
Colony* Colony::load_colony(const std::string& file_name)
{
	std::cout << "Loading Colony from file: "<< file_name << std::endl;
	std::ifstream input_file(file_name);

	if (!input_file.is_open())
	{
		throw Simple_Message_Exception("File could not be opened!");
	}

	std::string current_line;
	int width, height;

	// read colony-width
	if (std::getline(input_file, current_line))
	{
		if (Utility::is_number(current_line))
		{
			width = std::stoi(current_line);
		}
		else
		{
			throw Simple_Message_Exception(
				"Invalid Argument for parameter: <width>");
		}
	}

	// read colony-height
	if (std::getline(input_file, current_line))
	{
		if (Utility::is_number(current_line))
		{
			height = std::stoi(current_line);
		}
		else
		{
			throw Simple_Message_Exception(
				"Invalid Argument for parameter: <height>");
		}
	}

	// setting up temporary vector for all map-tiles
	std::vector<Tile> temp_tiles;
	temp_tiles.reserve(width*height);

	// setting up temporary vector for enemy robots
	std::vector<Robot> temp_robots;

	// setting up temp vector for doors
	std::vector<Door> temp_doors;

	bool hasStart = false;
	bool hasEnd = false;

	// save the coordinates to create and push the patchbot-robot object
	// in the last position of the robots-vector
	int patchbot_x;
	int patchbot_y;

	// iterate through the remaining lines of the textfile
	// containing the level-data
	int y = 0;
	while (std::getline(input_file, current_line))
	{
		// check if there is a next line to read;
		// if there is, check if the amount of chars matches the width
		if (y < height)
		{
			// check if current line matches the specified width
			if (current_line.size() == width)
			{
				std::cout << current_line << std::endl; // debug
				// iterate trough the characters of the current line
				for (int x = 0; x < width; x++)
				{
					char current_char = current_line[x];
					// check if read char is a robot
					// if so add it to the robots vector
					if (isdigit(current_char))
					{
						// check if the number is in the valid range
						// if so add it to the enemy-robots vector
						if (current_char <= 55 && current_char >= 49)
						{
							temp_robots.push_back(
								Robot(x,
									  y,
									  static_cast<RobotType>(current_char)
								)
							);
				
							temp_tiles.push_back(Tile(ENEMY_SPAWN));
						}
					}
					// if the read char is not a number,
					// then it has to be a tile or throw an exception
					else
					{
						TileType tile_type =
							Utility::char_to_tile_type(current_char);
						// throws exception if the current_char
						// refers to an unknown symbol
						temp_tiles.push_back(
							Tile(Utility::char_to_tile_type(current_char))
						);
						
						if (tile_type == TileType::MANUAL_DOOR_CLOSED ||
							tile_type == TileType::AUTO_DOOR_CLOSED)
						{
							temp_doors.push_back(
								Door(x, y));
						}

						// check if the current character is the player's
						// starting location,
						// if that is the case initialize the player object;
						// set the hasStart and hasEnd flags
						if (current_char == 'p')
						{
							if (!hasStart)
							{
								patchbot_x = x;
								patchbot_y = y;
								hasStart = true;
							}
							else
							{
								throw Simple_Message_Exception(
									"Colony can only have one starting point");
							}
						}else if (current_char == 'P')
						{
							hasEnd = true;
						}
					}
				}
			}
			// throw exception if the current line is either too short or
			// too long
			else if (current_line.size() < width)
			{
				std::stringstream temp_string_stream;
				temp_string_stream << "Line " << (y + 1);
				temp_string_stream << " is shorter than the specified length!";
				throw Simple_Message_Exception(temp_string_stream.str());
			}
			else if (current_line.size() > width)
			{
				std::stringstream temp_string_stream;
				temp_string_stream << "Line " << (y + 1) <<
					" is longer than the specified length!";
				throw Simple_Message_Exception(temp_string_stream.str());
			}
		}
		// invoked if the textfile is not containg the specified amount of lines
		// in order to initialize the colony object
		else
		{
			throw Simple_Message_Exception("File contains too many lines!");
		}
		y++;
	}

	// check if the file had enough lines
	if (!(y == height))
	{
		throw Simple_Message_Exception(
			"File contains less than the specified number of lines!");
	}

	// check the hasStart and hasEnd flags, if one of them or both are false
	// throw an exception
	if (hasStart == false)
	{
		throw Simple_Message_Exception("No starting point found!");
	}
	else
	{
		temp_robots.push_back(Robot(patchbot_x, patchbot_y, PATCHBOT));
	}
	if (hasEnd == false)
	{
		throw Simple_Message_Exception("No end point found!");
	}


	// if all values have been correctly setup create and return a pointer to
	// the loaded colony
	Colony* return_colony =
		new Colony(width, height, temp_robots, temp_tiles, temp_doors);
	std::cout << "Colony successfully loaded!" << std::endl;
	return return_colony;
}