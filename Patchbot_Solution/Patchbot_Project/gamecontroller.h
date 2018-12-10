#ifndef __GAME_CONTROLLER_DEFINED__
#define __GAME_CONTROLLER_DEFINED__

#include <string>

#include "src/colony.h"
#include "src/texture.h"

class GameController
{
public:
	GameController();
	~GameController();

	// loads a colony from a given filename and takes care of the setup
	void load_and_initialize_colony(const std::string& p_file_path);

	void load_textures();

private:
	// stores the currently displayed colony
	std::shared_ptr<Colony> m_current_colony;

	std::shared_ptr<std::vector<Texture>> ground_textures;

	std::shared_ptr<std::vector<Texture>> robot_textures;
};

#endif

