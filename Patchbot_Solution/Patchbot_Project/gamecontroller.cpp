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
	std::string ground_texture_paths[] = {
		"boden.tga",
		"boden_start_patchbot.tga",
		"boden_start_gegner.tga",
		"gefahr_abgrund.tga",
		"gefahr_wasser.tga",
		"hauptserver.tga",
		"hindernis_aliengras.tga",
		"hindernis_schotter.tga",
		"hindernis_geheimgang.tga",
		"tuer_manuell_offen.tga",
		"tuer_manuell_geschlossen.tga",
		"tuer_automatisch_offen.tga",
		"tuer_automatisch_geschlossen.tga",
		"wand_beton.tga",
		"wand_fels.tga"
	};

	/*std::map<TileType, std::string> tile_paths;
	tile_paths.insert(std::make_pair(TileType::PATCHBOT_SPAWN, "..."));*/

	// load the textures into the map
	m_ground_textures = std::make_shared<std::map<TileType, QImage>>(
		std::map<TileType, QImage>());

	for (int i = 0; i < LAST_TILE; i++)
	{
		const Texture temp_texture = Texture::load_texture(
			(ground_texture_base_path + ground_texture_paths[i]));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into the map with a given TileType,
		// returned by a static cast
		m_ground_textures->insert(
			std::pair<TileType, QImage>(
				static_cast<TileType>(i),
				temp_image.mirrored(false, true).copy() ));
	}


	// load robot textures
	// setup path-variables
	std::string robot_texture_base_path = "src\\textures\\roboter\\";
	std::string robot_texture_paths[] = {
		"patchbot.tga",
		"typ1_bugger.tga",
		"typ2_pusher.tga",
		"typ3_digger.tga",
		"typ4_swimmer.tga",
		"typ5_follower.tga",
		"typ6_hunter.tga",
		"typ7_sniffer.tga",
		"dead.tga"
	};

	// create and fill the map with the robot images
	m_robot_textures = std::make_shared<std::map<RobotType, QImage>>(
		std::map<RobotType, QImage>());

	// calculate length of robot_type enum and load all robot images
	for (int i = 0; i < (LAST_ROBOT - PATCHBOT); i++)
	{
		const Texture temp_texture = Texture::load_texture(
			(robot_texture_base_path + robot_texture_paths[i]));

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
		m_robot_textures->insert(
			std::pair<RobotType, QImage>(
				static_cast<RobotType>( (i + PATCHBOT) ),
				temp_image.mirrored(false, true).copy() ));
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

const QImage& GameController::get_ground_texture_by_tile_type(
	const TileType & p_tile) const
{
	return m_ground_textures->find(p_tile)->second;
}

const QImage& GameController::get_robot_texture_by_robot_type(
	const RobotType& p_robot_type) const
{
	return m_robot_textures->find(p_robot_type)->second;
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