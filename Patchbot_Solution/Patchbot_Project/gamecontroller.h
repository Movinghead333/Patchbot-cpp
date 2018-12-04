#ifndef __GAME_CONTROLLER_DEFINED__
#define __GAME_CONTROLLER_DEFINED__

#include <string>

#include "src/colony.h"

class GameController
{
public:
	GameController();
	~GameController();

	// loads a colony from a given filename and takes care of the setup
	void load_and_initialize_colony(const std::string& p_file_path);

private:
	std::shared_ptr<Colony> m_current_colony;
};

#endif

