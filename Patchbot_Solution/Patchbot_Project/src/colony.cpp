#include "colony.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Colony::Colony(
	const int p_width,
	const int p_height,
	const std::vector<std::shared_ptr<Robot>>& p_enemy_robots,
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

void Colony::change_occupation(Tile & old_tile, Tile & new_tile)
{
	old_tile.set_occupied(false);
	new_tile.set_occupied(true);
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
	return *m_robots[m_robots.size()-1];
}

 std::vector<Door>& Colony::get_doors()
 {
	 return m_doors;
 }

 Tile& Colony::get_editable_tile_ref_by_coordiantes(int p_x, int p_y)
 {
	 return m_tiles[p_x + (m_width * p_y)];
 }

 Tile & Colony::get_editable_tile_ref_by_coordiantes(Point2D p_position)
 {
	 return m_tiles[p_position.x + (m_width * p_position.y)];
 }

std::vector<std::shared_ptr<Robot>>& Colony::get_robots()
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
	std::vector<std::shared_ptr<Robot>> temp_robots;

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
					BestPath current_nav_mesh_value =
						Utility::char_to_nav_mesh_value(current_char);
					// check if read char is a robot
					// if so add it to the robots vector
					if (isdigit(current_char))
					{
						// check if the number is in the valid range
						// if so add it to the enemy-robots vector
						if (current_char <= 55 && current_char >= 49)
						{
							switch (current_char)
							{
							case 49:
								temp_robots.push_back(std::make_shared<Bugger>(
									Bugger(Point2D(x, y),
										static_cast<RobotType>(current_char)
									)
									));
								break;

							case 50:
							case 51:
							case 52:
								temp_robots.push_back(
									std::make_shared<LineRobot>(
									LineRobot(Point2D(x, y),
										static_cast<RobotType>(current_char)
									)
									));
								break;

							case 53:
							case 54:
							case 55:
								temp_robots.push_back(
									std::make_shared<PathfinderRobot>(
										PathfinderRobot(Point2D(x, y),
											static_cast<RobotType>(current_char)
										)
										));
								break;

							default:
								temp_robots.push_back(std::make_shared<Robot>(
									Robot(Point2D(x, y),
										static_cast<RobotType>(current_char)
									)
									));
								break;
							}
							
				
							temp_tiles.push_back(
								Tile(ENEMY_SPAWN,
									 current_nav_mesh_value,
									 true));
						}
					}
					// if the read char is not a number,
					// then it has to be a tile or throw an exception
					else
					{
						// throws exception if the current_char
						// refers to an unknown symbol
						TileType tile_type =
							Utility::char_to_tile_type(current_char);
						
						temp_tiles.push_back(
							Tile(tile_type, current_nav_mesh_value, false));
						
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
								temp_tiles.back().set_occupied(true);
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
		temp_robots.push_back(std::make_shared<Robot>(
			Robot(Point2D(patchbot_x, patchbot_y), RobotType::PATCHBOT)));
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

// generates the navigation mesh for the currently loaded colony 
void Colony::generate_nav_mesh()
{
	// reset nav_mesh
	for (Tile& tile : m_tiles)
	{
		if (tile.get_m_best_path() != BestPath::UNREACHABLE)
		{
			tile.set_m_best_path(BestPath::UNSET);
		}
	}

	// get patchbot from robots vector
	const Robot& patchbot = *m_robots.back();
	int p_patchbot_x = patchbot.get_x_coordinate();
	int p_patchbot_y = patchbot.get_y_coordinate();

	// set the tile patchbot is on as target for pathfinding
	Tile& patchbot_tile = get_editable_tile_ref_by_coordiantes(
		p_patchbot_x, p_patchbot_y);

	patchbot_tile.set_m_best_path(BestPath::TARGET);

	// create the priority queue for dijkstra algorithm
	std::priority_queue<Node> node_stack;

	// create the first node which is patchbots's location with a distance of 0
	node_stack.emplace(p_patchbot_x, p_patchbot_y, 0);

	// go through the list until there no more nodes to be checked
	while (!node_stack.empty())
	{
		// get the current node
		const Node current_node = node_stack.top();

		// delete the current element from the priority queue
		node_stack.pop();

		// now checks all four directions for unset tiles and set those based
		// on the current shortest path
		
		// up
		if (current_node.m_y - 1 >= 0)
		{
			// get a reference to the tile which currently processed
			Tile& up_tile = get_editable_tile_ref_by_coordiantes(
				current_node.m_x, current_node.m_y - 1);

			// if the tile is not set then set it
			if (up_tile.get_m_best_path() == BestPath::UNSET)
			{
				// set the tiles pathing variable 
				up_tile.set_m_best_path(BestPath::PATH_DOWN);

				// calculate the distance to this tile for further calculations
				int distance = Utility::get_distance_from_tile_Type(
					up_tile.get_tile_type()) + current_node.m_distance;
				
				// put the current tile in the list in order for it to have
				// its neighbours be processed aswell
				node_stack.emplace(
					current_node.m_x,
					current_node.m_y - 1,
					distance);
			}
		}
		

		// right
		if (current_node.m_x + 1 < m_width)
		{
			Tile& right_tile = get_editable_tile_ref_by_coordiantes(
				current_node.m_x + 1, current_node.m_y);


			if (right_tile.get_m_best_path() == BestPath::UNSET)
			{
				right_tile.set_m_best_path(BestPath::PATH_LEFT);

				int distance = Utility::get_distance_from_tile_Type(
					right_tile.get_tile_type()) + current_node.m_distance;

				node_stack.emplace(
					current_node.m_x + 1,
					current_node.m_y,
					distance);
			}
		}


		// down
		if (current_node.m_y + 1 < m_height)
		{
			Tile& down_tile = get_editable_tile_ref_by_coordiantes(
				current_node.m_x, current_node.m_y + 1);


			if (down_tile.get_m_best_path() == BestPath::UNSET)
			{
				down_tile.set_m_best_path(BestPath::PATH_UP);

				int distance = Utility::get_distance_from_tile_Type(
					down_tile.get_tile_type()) + current_node.m_distance;

				node_stack.emplace(
					current_node.m_x,
					current_node.m_y + 1,
					distance);
			}
		}


		// left
		if (current_node.m_x - 1 >= 0)
		{
			Tile& left_tile = get_editable_tile_ref_by_coordiantes(
				current_node.m_x - 1, current_node.m_y);


			if (left_tile.get_m_best_path() == BestPath::UNSET)
			{
				left_tile.set_m_best_path(BestPath::PATH_RIGHT);

				int distance = Utility::get_distance_from_tile_Type(
					left_tile.get_tile_type()) + current_node.m_distance;

				node_stack.emplace(
					current_node.m_x - 1,
					current_node.m_y,
					distance);
			}
		}
		
		
	}
}
