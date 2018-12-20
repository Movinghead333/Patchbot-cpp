#include "gamecontroller.h"



GameController::GameController()
{
	// load images into controller
	// throws Simple_Message_Exception which is caught in MainWindow
	load_textures();
}

void GameController::load_and_initialize_colony(
	const std::string& p_file_path)
{
	// load a colony from file into controller
	m_current_colony = std::make_shared<Colony>(
		*Colony::load_colony(p_file_path));
}

void GameController::load_textures()
{
	// load ground textures
	// setup path-variables
	std::string ground_texture_base_path = "src\\textures\\umgebungen\\";

	// temp map to link paths to TileTypes
	std::map<TileType, std::string> tile_paths;

	tile_paths.insert(
		std::make_pair(
			TileType::STEELPLANKS, "boden.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::PATCHBOT_SPAWN, "boden_start_patchbot.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ENEMY_SPAWN, "boden_start_gegner.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ABYSS, "gefahr_abgrund.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::WATER, "gefahr_wasser.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ROOT_SERVER, "hauptserver.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ALIEN_GRASS, "hindernis_aliengras.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::GRAVEL, "hindernis_schotter.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::SECRET_ENTRANCE, "hindernis_geheimgang.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::MANUAL_DOOR_OPEN, "tuer_manuell_offen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::MANUAL_DOOR_CLOSED, "tuer_manuell_geschlossen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::AUTO_DOOR_OPEN, "tuer_automatisch_offen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::AUTO_DOOR_CLOSED, "tuer_automatisch_geschlossen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::INDESTRUCTABLE_WALL, "wand_beton.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::DESTRUCTABLE_WALL, "wand_fels.tga"));
		

	// load the textures into the map
	m_ground_textures = std::map<TileType, std::shared_ptr<QImage>>();

	for (const std::pair<TileType, std::string>& resource_pair : tile_paths)
	{
		const Texture temp_texture = Texture::load_texture(
			(ground_texture_base_path + resource_pair.second));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into a shared_ptr and then insert it 
		// with a matching TileType key
		m_ground_textures.insert(
			std::pair<TileType, std::shared_ptr<QImage>>(
				resource_pair.first,
				std::make_shared<QImage>(
					temp_image.mirrored(false, true).copy()
				) 
			)
		);
	}


	// load robot textures
	// setup path-variables
	std::string robot_texture_base_path = "src\\textures\\roboter\\";

	std::map<RobotType, std::string> robot_resource_map;

	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::PATCHBOT, "patchbot.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::BUGGER,   "typ1_bugger.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::PUSHER,   "typ2_pusher.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::DIGGER,   "typ3_digger.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::SWIMMER,  "typ4_swimmer.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::FOLLOWER, "typ5_follower.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::HUNTER,   "typ6_hunter.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::SNIFFER,  "typ7_sniffer.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::DEAD,     "dead.tga"));


	// create and fill the map with the robot images
	m_robot_textures = std::map<RobotType, std::shared_ptr<QImage>>();

	// calculate length of robot_type enum and load all robot images
	for (const std::pair<RobotType, std::string>& resource : robot_resource_map)
	{
		const Texture temp_texture = Texture::load_texture(
			(robot_texture_base_path + resource.second));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into the vector
		m_robot_textures.insert(
			std::pair<RobotType, std::shared_ptr<QImage>>(
				resource.first,
				std::make_shared<QImage>(
					temp_image.mirrored(false, true).copy()
				)
			)
		);
	}
}

Colony& GameController::get_current_colony()
{
	return *m_current_colony.get();
}

bool GameController::colony_loaded() const
{
	return m_current_colony != nullptr;
}

const std::shared_ptr<QImage> GameController::get_ground_texture_by_tile_type(
	const TileType & p_tile) const
{
	return m_ground_textures.find(p_tile)->second;
}

const std::shared_ptr<QImage> GameController::get_robot_texture_by_robot_type(
	const RobotType& p_robot_type) const
{
	return m_robot_textures.find(p_robot_type)->second;
}

void GameController::set_x_scrollbar_pos(int p_new_pos)
{
	x_scrollbar_pos = p_new_pos;
}

void GameController::set_y_scrollbar_pos(int p_new_pos)
{
	y_scrollbar_pos = p_new_pos;
}

int GameController::get_x_scrollbar_pos() const
{
	return x_scrollbar_pos;
}

int GameController::get_y_scrollbar_pos() const
{
	return y_scrollbar_pos;
}

void GameController::set_render_width(int p_new_width)
{
	render_width = p_new_width;
}

void GameController::set_render_height(int p_new_height)
{
	render_height = p_new_height;
}

int GameController::get_render_width() const
{
	return render_width;
}

int GameController::get_render_height() const
{
	return render_height;
}