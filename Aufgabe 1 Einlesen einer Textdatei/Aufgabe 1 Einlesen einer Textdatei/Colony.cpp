#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "colony.h"

Colony::Colony(const int p_width, const int p_height, Robot* p_patchbot,
	std::vector<Robot> p_enemy_robots, std::vector<Tile> p_tiles) :
	m_width(p_width), m_height(p_height), m_patchbot(p_patchbot),
	m_enemy_robots(p_enemy_robots), m_tiles(p_tiles) {}


const Tile Colony::get_tile_by_coordinates(const int & x, const int & y) const
{
	return m_tiles[x + (m_width * y)];
}

const int Colony::get_width() const
{
	return m_width;
}

const int Colony::get_height() const
{
	return m_height;
}

const std::vector<Tile>& Colony::get_tiles() const
{
	return m_tiles;
}

const Robot* Colony::get_patch_bot() const
{
	return m_patchbot;
}

const std::vector<Robot> Colony::get_enemy_robots() const
{
	return m_enemy_robots;
}


// load a colony by filename and return a pointer to the created object
//
Colony * Colony::load_colony(const std::string& file_name)
{
	std::cout << "Loading Colony from file: "<< file_name << std::endl;
	std::ifstream input_file(file_name);

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
			throw Simple_Message_Exception("Invalid Argument for parameter: <width>");
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
			throw Simple_Message_Exception("Invalid Argument for parameter: <height>");
		}
	}

	// setting up temporary vector for all map-tiles
	std::vector<Tile> temp_tiles;
	temp_tiles.reserve(width*height);

	// setting up temporary vector for enemy robot starting points
	std::vector<Robot>* temp_robots = new std::vector<Robot>;

	// setting up temporary variable for the location of patch_bot
	Robot* temp_patch_bot = nullptr;

	bool hasStart = false;
	bool hasEnd = false;

	// iterate through the remaining lines of the textfile containing the level-data
	for (int y = 0; y < height; y++)
	{
		// check if there is a next line to read;
		// if there is, check if the amount of chars matches the width
		if (std::getline(input_file, current_line))
		{
			// check if current line matches the specified width
			if (current_line.size() == width)
			{
				std::cout << current_line << std::endl; // debug
				// iterate trough the characters of the current line
				for (int x = 0; x < width; x++)
				{
					char current_char = current_line[x];
					// check if read char is a robot if so add it to the robots vector
					if (isdigit(current_char))
					{
						// check if the number is in the valid range if so add it to the enemy-robots vector
						if (current_char <= 55 && current_char >= 49)
						{
							(*temp_robots).push_back(Robot(x, y, static_cast<RobotType>(current_char)));
				
							temp_tiles.push_back(Tile(ENEMY_SPAWN));
						}
					}
					// if the read char is not a number it has to be a tile or throw an exception
					else
					{
						// throws exception if the current_char refers to an unknown symbol
						temp_tiles.push_back(Tile(current_char));

						// check if the current character is the player starting location
						// if that is the case initialize the player object
						if (current_char == 'p')
						{
							temp_patch_bot = new Robot(x, y, PATCHBOT);
							hasStart = true;
						}
						else if (current_char == 'P')
						{
							hasEnd = true;
						}
					}
				}
			}
			// throw exception if the current line is either too short or too long
			else
			{
				std::stringstream temp_string_stream;
				temp_string_stream << "Line " << (y + 1) << " does not match the specified width!";
				throw Simple_Message_Exception(temp_string_stream.str());
			}
		}
		// invoked if the textfile is not containg the specified amount of lines
		// in order to initialize the colony object
		else
		{
			throw Simple_Message_Exception("File does not contain the necessary number of lines!");
		}
	}
	if (hasStart == false)
	{
		throw Simple_Message_Exception("No starting point found!");
	}
	else if (hasEnd == false)
	{
		throw Simple_Message_Exception("No end point found!");
	}


	Colony* return_colony = new Colony(width, height, temp_patch_bot, *temp_robots, temp_tiles);
	return return_colony;
}