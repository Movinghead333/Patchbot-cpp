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
	const std::vector<Door>& p_doors,
	const std::vector<Point2D> p_destroyable_walls)
	:
	m_width(p_width),
	m_height(p_height),
	m_robots(p_enemy_robots),
	m_tiles(p_tiles),
	m_doors(p_doors),
	m_destroyable_walls(p_destroyable_walls)
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

 Patchbot& Colony::get_patch_bot() 
{
	return static_cast<Patchbot&>(*m_robots[m_robots.size()-1]);
}

 std::shared_ptr<Robot>& Colony::get_robot_by_id(int p_id)
 {
	 return m_robots[p_id];
 }

 std::vector<Door>& Colony::get_doors()
 {
	 return m_doors;
 }

 Tile& Colony::get_editable_tile_ref_by_coordinates(int p_x, int p_y)
 {
	 return m_tiles[p_x + (m_width * p_y)];
 }

 Tile & Colony::get_tile_by_pos(Point2D p_position)
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

	// 
	std::vector<Point2D> temp_destroyable_walls;

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
					//

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
									 temp_robots.size() - 1));
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
							Tile(tile_type, current_nav_mesh_value, -1));
						
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
						else if (current_char == 'M')
						{
							temp_destroyable_walls.push_back(Point2D(x, y));
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
		temp_robots.push_back(std::make_shared<Patchbot>(
			Patchbot(Point2D(patchbot_x, patchbot_y), RobotType::PATCHBOT)));
		temp_tiles[patchbot_y * width + patchbot_x].set_robot_id(
			temp_robots.size() - 1);
		temp_tiles[patchbot_y * width + patchbot_x].set_robot_id_back_up(
			temp_robots.size() - 1);
	}
	if (hasEnd == false)
	{
		throw Simple_Message_Exception("No end point found!");
	}


	// if all values have been correctly setup create and return a pointer to
	// the loaded colony
	Colony* return_colony = new Colony(
		width,
		height,
		temp_robots,
		temp_tiles,
		temp_doors,
		temp_destroyable_walls);

	std::cout << "Colony successfully loaded!" << std::endl;
	return return_colony;
}

void Colony::reset_colony()
{
	for (Tile& tile : m_tiles)
	{
		tile.reset();
	}

	for (const Point2D& destroyable_wall : m_destroyable_walls) {
		Tile& current_tile = get_tile_by_pos(destroyable_wall);

		current_tile.set_m_tile_type(TileType::DESTRUCTABLE_WALL);
		current_tile.set_m_best_path(BestPath::UNREACHABLE);
	}

	for (std::shared_ptr<Robot>& robot : m_robots)
	{
		robot->reset_robot();
	}

	for (Door& door : m_doors)
	{
		door.reset();
	}
}

void Colony::update_doors()
{
	for (Door& temp_door : m_doors)
	{
		Tile& temp_door_tile = get_editable_tile_ref_by_coordinates(
			temp_door.m_x, temp_door.m_y);
		temp_door.update(temp_door_tile);
	}
}

// generates the navigation mesh for the currently loaded colony 
void Colony::generate_nav_mesh()
{
	// reset nav_mesh
	for (Tile& tile : m_tiles)
	{
		tile.set_pathing_done(false);
	}

	// get patchbot from robots vector
	const Robot& patchbot = *m_robots.back();
	int p_patchbot_x = patchbot.get_x_coordinate();
	int p_patchbot_y = patchbot.get_y_coordinate();

	// set the tile patchbot is on as target for pathfinding
	Tile& patchbot_tile = get_editable_tile_ref_by_coordinates(
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
			Tile& up_tile = get_editable_tile_ref_by_coordinates(
				current_node.m_x, current_node.m_y - 1);

			// if the tile is not set then set it
			if (up_tile.get_m_best_path() != BestPath::UNREACHABLE &&
				!up_tile.get_pathing_done())
			{
				// set the tiles pathing variable 
				up_tile.set_m_best_path(BestPath::PATH_DOWN);

				// indicates that pathing for this tile is done
				up_tile.set_pathing_done(true);

				// add the node only if it is not currently occupied by a robot
				if (!up_tile.get_occupied())
				{
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
		}
		

		// right
		if (current_node.m_x + 1 < m_width)
		{
			Tile& right_tile = get_editable_tile_ref_by_coordinates(
				current_node.m_x + 1, current_node.m_y);


			if (right_tile.get_m_best_path() != BestPath::UNREACHABLE &&
				!right_tile.get_pathing_done())
			{
				right_tile.set_m_best_path(BestPath::PATH_LEFT);

				right_tile.set_pathing_done(true);

				if (!right_tile.get_occupied())
				{
					int distance = Utility::get_distance_from_tile_Type(
						right_tile.get_tile_type()) + current_node.m_distance;

					node_stack.emplace(
						current_node.m_x + 1,
						current_node.m_y,
						distance);
				}
			}
		}


		// down
		if (current_node.m_y + 1 < m_height)
		{
			Tile& down_tile = get_editable_tile_ref_by_coordinates(
				current_node.m_x, current_node.m_y + 1);


			if (down_tile.get_m_best_path() != BestPath::UNREACHABLE &&
				!down_tile.get_pathing_done())
			{
				down_tile.set_m_best_path(BestPath::PATH_UP);

				down_tile.set_pathing_done(true);

				if (!down_tile.get_occupied())
				{
					int distance = Utility::get_distance_from_tile_Type(
						down_tile.get_tile_type()) + current_node.m_distance;

					node_stack.emplace(
						current_node.m_x,
						current_node.m_y + 1,
						distance);
				}
			}
		}


		// left
		if (current_node.m_x - 1 >= 0)
		{
			Tile& left_tile = get_editable_tile_ref_by_coordinates(
				current_node.m_x - 1, current_node.m_y);


			if (left_tile.get_m_best_path() != BestPath::UNREACHABLE &&
				!left_tile.get_pathing_done())
			{
				left_tile.set_m_best_path(BestPath::PATH_RIGHT);

				left_tile.set_pathing_done(true);

				if (!left_tile.get_occupied())
				{
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
}

void Colony::print_robot_id_matrix() const
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (m_tiles[y * m_width + x].get_robot_id() != -1)
			{
				std::cout << m_tiles[y * m_width + x].get_robot_id() << " ";
			}
			else
			{
				std::cout << "+ ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Colony::print_occupiation_matrix() const
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			if (m_tiles[y * m_width + x].get_occupied())
			{
				std::cout << "1 ";
			}
			else
			{
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Colony::move_robot_on_map(Robot& p_robot, Point2D p_target_position)
{
	// get an editable ref to old tile
	Tile& old_tile =
		get_tile_by_pos(p_robot.get_position());

	// temp robot_id
	int robot_id = old_tile.get_robot_id();

	// set old tile to free
	old_tile.set_robot_id(-1);

	// update the robot's position to its new target position
	p_robot.update_position(p_target_position);

	// set the new tile to occupied
	get_tile_by_pos(p_robot.get_position()).
		set_robot_id(robot_id);
}

bool Colony::is_in_map_boundries(const Point2D & p_point) const
{
	return p_point.x >= 0 && p_point.x < m_width &&
		   p_point.y >= 0 && p_point.y < m_height;
}

void Colony::update_robot_position(Point2D p_old_pos, Point2D p_new_pos)
{
	// get editable ref to old tile
	Tile& old_tile = get_editable_tile_ref_by_coordinates(
		p_old_pos.x, p_old_pos.y);

	// temporarly store the robot_id
	int robot_id = old_tile.get_robot_id();

	// reset the old tile
	old_tile.set_robot_id(-1);

	Robot& robot = *get_robot_by_id(robot_id);

	Tile& new_tile = get_editable_tile_ref_by_coordinates(
		p_new_pos.x, p_new_pos.y);

	
	new_tile.set_robot_id(robot_id);
	

	// lastly update the robots coordinates
	get_robot_by_id(robot_id)->update_position(p_new_pos);
}