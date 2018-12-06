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

	// set methods for updating the data model
	void set_x_offset(int p_x_offset);
	void set_y_offset(int p_y_offset);


	// gets called upon reiszeEvent in main_window and retreives the new 
	// dimensions of the render area
	void update_render_dimensions(int p_render_width, int p_render_height);


	int render_width;
	int render_height;

private:
	// stores the currently displayed colony
	std::shared_ptr<Colony> m_current_colony;

	// render area properties
	int x_offset;
	int y_offset;

};

#endif

