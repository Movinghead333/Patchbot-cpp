#include "gamecontroller.h"



GameController::GameController()
{
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



