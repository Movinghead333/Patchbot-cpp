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

void GameController::set_x_offset(int p_x_offset)
{
	x_offset = p_x_offset;
}

void GameController::set_y_offset(int p_y_offset)
{
	y_offset = p_y_offset;
}

void GameController::update_render_dimensions(int p_render_width, int p_render_height)
{
	render_width = p_render_width;
	render_height = p_render_height;
}




