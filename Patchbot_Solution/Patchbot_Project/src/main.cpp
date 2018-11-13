#include <iostream>
#include <fstream>

#include "colony.h"
#include "texture.h"

// vc: 8

void write_colony_to_file(
	const Colony* input_colony,
	const char* original_final_name
);

int main(int argc, char *argv[])
{
	// try loading a tga file and rewriting it to a tga file
	try
	{
		std::shared_ptr<Texture> new_colony =
			std::make_shared<Texture>( Texture::loadTexture(argv[1]) );
	}
	// catch all specified exceptions
	catch (const Simple_Message_Exception& e)
	{
		std::cerr << e.m_error_message << std::endl;
	}
	// catch any non aticipated exceptions
	catch (...)
	{
		std::cout << "Unchecked exception thrown" << std::endl;
	}


	/*
	
	// try loading a colony from commandline arg and rewrite it to a new file
	try
	{
		std::shared_ptr<Colony> new_colony =
			std::make_shared<Colony>(*Colony::load_colony(argv[1]));
		write_colony_to_file(new_colony.get(), argv[1]);
	}
	// catch all specified exceptions
	catch (const Simple_Message_Exception& e)
	{
		std::cerr << e.m_error_message << std::endl;
	}
	// catch any non aticipated exceptions
	catch (...)
	{
		std::cout << "Unchecked exception thrown" << std::endl;
	}

	*/

	std::cin.get();
	return 0;
}



// writes a colony back to a txt file for testing purposes
void write_colony_to_file(
	const Colony* input_colony,
	const char* original_final_name
)
{
	std::ofstream output_file;
	std::string file_name = "new_";
	file_name += original_final_name;
	output_file.open(file_name);
	Colony c = *input_colony;

	const int width = c.get_width();
	const int height = c.get_height();

	output_file << width << std::endl;
	output_file << height << std::endl;

	// create vector for storing all the level-data in chars
	std::vector<char> level_data(width*height);
	// std::cout << level_data.size() << std::endl; // debug

	// get refernce-vector to all tiles in the current colony
	const std::vector<Tile> temp_tiles = c.get_tiles();


	for (int i = 0; i < temp_tiles.size(); i++)
	{
		if ((temp_tiles[i].get_tile_type()) != ENEMY_SPAWN) {
			level_data[i] = Tile::get_source_char(temp_tiles[i]);
		}
	}


	// add the robots back to level_data
	std::vector<Robot> temp_robots = c.get_enemy_robots();
	// std::cout << temp_robots.size() << std::endl; // debug

	for (Robot robot : temp_robots)
	{
		int temp_index = robot.get_x_coordinate() + 
						(robot.get_y_coordinate() * width);
		level_data[temp_index] = (int)robot.get_robot_type();
	}


	
	for (int i = 0; i < temp_tiles.size(); i++)
	{
		if (i != 0 && i != width * height && i % width == 0)
		{
			output_file << std::endl;
		}
		output_file << level_data[i];
	}

	output_file.close();
}