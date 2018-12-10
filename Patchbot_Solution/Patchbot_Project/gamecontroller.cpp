#include "gamecontroller.h"



GameController::GameController()
{
	load_textures();
}


GameController::~GameController()
{
}

void GameController::load_and_initialize_colony(
	const std::string& p_file_path)
{
	m_current_colony = std::make_shared<Colony>(
		*Colony::load_colony(p_file_path)
	);
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

	// load the textures into the vector
	m_ground_textures = std::make_shared<std::vector<Texture>>(
		std::vector<Texture>()
		);
	for (std::string current_file_name : ground_texture_paths)
	{
		m_ground_textures->push_back(Texture::load_texture(
			(ground_texture_base_path + current_file_name) ));
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

	// create and fill the vector with the robot images
	m_robot_textures = std::make_shared<std::vector<Texture>>(
		std::vector<Texture>()
		);
	for (std::string current_file_name : robot_texture_paths)
	{
		m_robot_textures->push_back(Texture::load_texture(
			(robot_texture_base_path + current_file_name)));
	}
}

const Colony& GameController::get_current_colony() const
{
	return *m_current_colony.get();
}

bool GameController::colony_loaded() const
{
	return m_current_colony != nullptr;
}

const Texture & GameController::get_ground_texture_by_tile_type(
	const TileType & p_tile) const
{
	std::vector<Texture>& temp_textures = *m_ground_textures;
	switch (p_tile)
	{
	case STEELPLANKS:		  return temp_textures[0];   break;
	case PATCHBOT_SPAWN:	  return temp_textures[1];   break;
	case ENEMY_SPAWN:		  return temp_textures[2];   break;
	case ABYSS:				  return temp_textures[3];   break;
	case WATER:				  return temp_textures[4];   break;
	case ROOT_SERVER:		  return temp_textures[5];   break;
	case ALIEN_GRASS:		  return temp_textures[6];   break;
	case GRAVEL:			  return temp_textures[7];   break;
	case SECRET_ENTRANCE:     return temp_textures[8];   break;
	case MANUAL_DOOR_OPEN:    return temp_textures[9];   break;
	case MANUAL_DOOR_CLOSED:  return temp_textures[10];  break;
	case AUTO_DOOR_OPEN:	  return temp_textures[11];  break;
	case AUTO_DOOR_CLOSED:	  return temp_textures[12];  break;
	case INDESTRUCTABLE_WALL: return temp_textures[13];  break;
	case DESTRUCTABLE_WALL:   return temp_textures[14];  break;
	default: throw Simple_Message_Exception("Input tiletype non existent!");
	}
}

void GameController::set_x_scrollbar_pos(int p_new_pos)
{
	x_scrollbar_pos = p_new_pos;
}

void GameController::set_y_scrollbar_pos(int p_new_pos)
{
	y_scrollbar_pos = p_new_pos;
}

int GameController::get_x_scrollbar_pos()
{
	return x_scrollbar_pos;
}

int GameController::get_y_scrollbar_pos()
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

int GameController::get_render_width()
{
	return render_width;
}

int GameController::get_render_height()
{
	return render_height;
}




