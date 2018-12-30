#ifndef __GAME_CONTROLLER_DEFINED__
#define __GAME_CONTROLLER_DEFINED__

#include <string>

#include <qimage.h>

#include "src/colony.h"
#include "src/texture.h"
#include "patchbot_move.h"

class GameController
{
public:
	GameController();

	// loads a colony from a given filename and takes care of the setup
	void load_and_initialize_colony(const std::string& p_file_path);

	void load_textures();

	Colony& get_current_colony();

	bool colony_loaded() const;

	void add_move_to_current_program(MoveType p_move_type);

	// removes the most recently added command from the current program
	void remove_most_recently_added_move();

	// writes out the current program to console
	void display_current_program() const;

	// get QImage ref according to passed TileType
	const std::shared_ptr<QImage> get_ground_texture_by_tile_type(
		const TileType& p_tile) const;

	// get QImage ref according to passed RobotType
	const std::shared_ptr<QImage> get_robot_texture_by_robot_type(
		const RobotType& p_robot_type) const;

	// scrollbar getters and setters
	void set_x_scrollbar_pos(int p_new_pos);
	void set_y_scrollbar_pos(int p_new_pos);

	int get_x_scrollbar_pos() const;
	int get_y_scrollbar_pos() const;

	// render dimensions getters and setters
	void set_render_width(int p_new_width);
	void set_render_height(int p_new_height);

	int get_render_width() const;
	int get_render_height() const;

	// set repititionsS
	void set_m_repititions(QString p_combo_box_input);

	

private:
	// current scrollbar positions
	int x_scrollbar_pos = 0;
	int y_scrollbar_pos = 0;

	// size of the rendered area
	int render_width;
	int render_height;

	// currently selected amount of repetitions
	int m_repititions = 1; //TODO change default value

	// vector storing the current program
	std::vector<PatchbotMove> m_current_program;

	// stores the currently displayed colony
	std::shared_ptr<Colony> m_current_colony;

	// stores all graphics for ground tiles
	std::map<TileType, std::shared_ptr<QImage>> m_ground_textures;

	// stores all robot-graphics
	std::map<RobotType, std::shared_ptr<QImage>> m_robot_textures;
};

#endif

