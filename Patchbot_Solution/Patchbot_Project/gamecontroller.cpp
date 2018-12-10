#include "gamecontroller.h"



GameController::GameController()
{
	//load_textures();
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

	ground_textures = std::make_shared<std::vector<Texture>>(
		std::vector<Texture>()
		);
	for (std::string current_file_name : ground_texture_paths)
	{
		ground_textures->push_back(Texture::load_texture(
			(ground_texture_base_path + current_file_name) ));
	}


	// load robot textures
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

	robot_textures = std::make_shared<std::vector<Texture>>(
		std::vector<Texture>()
		);
	for (std::string current_file_name : robot_texture_paths)
	{
		robot_textures->push_back(Texture::load_texture(
			(robot_texture_base_path + current_file_name)));
	}
}


