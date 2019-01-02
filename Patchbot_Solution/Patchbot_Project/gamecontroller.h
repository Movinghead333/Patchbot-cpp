#ifndef __GAME_CONTROLLER_DEFINED__
#define __GAME_CONTROLLER_DEFINED__

#include <string>

#include <qimage.h>

#include "src/colony.h"
#include "src/texture.h"
#include "patchbot_move.h"
#include "game_state.h"

class GameController
{
public:
	/* LOGICAL CALCULATIONS AND INITIALIZATIONS FOR THE GAME */

	// creates an instance of the game controller loading all images
	// and initializing the current-program vector
	GameController();

	// loads a colony from a given filename and takes care of the setup
	void load_and_initialize_colony(const std::string& p_file_path);

	// loads all necessary textures for the game
	void load_textures();

	// returns wether a colony is currently stored in memory
	bool colony_loaded() const;

	// adds a move to current program based on the MoveType parameter
	// and the repititions variable saved in the controller
	void add_move_to_current_program(MoveType p_move_type);

	// returns a QString for the current program QLineEdit
	const QString get_currently_displayed_program_string() const;

	// removes the most recently added command from the current program
	void remove_most_recently_added_move();

	// writes out the current program to console
	void display_current_program() const;

	// get amount of commands which can be displayed in the qlineedit
	int calcualte_program_scrollbar_max() const;

	// check if the current program is not empty
	void validate_current_program() const;

	// start program execution
	void start_current_program();

	// execute a single time step in the current program
	void execute_single_step();

	bool calculate_collision(int x, int y);



	/* GETTERS AND SETTERS */

	// get QImage ref according to passed TileType
	const std::shared_ptr<QImage> get_ground_texture_by_tile_type(
		const TileType& p_tile) const;

	// get QImage ref according to passed RobotType
	const std::shared_ptr<QImage> get_robot_texture_by_robot_type(
		const RobotType& p_robot_type) const;

	// return a reference to currently loaded colony
	Colony& get_current_colony();

	// scrollbar getters and setters
	void set_x_scrollbar_pos(int p_new_pos);
	void set_y_scrollbar_pos(int p_new_pos);
	void set_program_scrollbar_pos(int p_new_pos);

	int get_x_scrollbar_pos() const;
	int get_y_scrollbar_pos() const;
	int get_program_scrollbar_pos() const;

	// render dimensions getters and setters
	void set_render_width(int p_new_width);
	void set_render_height(int p_new_height);

	int get_render_width() const;
	int get_render_height() const;

	// set repititions
	void set_m_repititions(QString p_combo_box_input);

	// getter and setter for m_max_chars
	void set_m_max_commands_in_lineedit(int p_max_chars);
	int get_m_max_commands_in_lineedit() const;

	// getter and setter for program_executing
	void set_m_automatic_mode_enabled(bool p_m_automatic_mode_enabled);
	bool get_m_automatic_mode_enabled() const;

	// getter and setter for current game state
	GameState get_game_state() const;
	void set_game_state(GameState p_game_state);

private:
	/* PRIVATE MEMBERS AND GUI DATA */

	// flag which determins wether automatic mode is currently on or off
	// off by default
	bool m_automatic_mode_enabled = false;

	// current gamestate
	GameState m_game_state = GameState::GAME_NOT_STARTED;

	// stores the index of the currently executed move
	int m_program_index;

	// stores the currently executed move
	PatchbotMove m_current_move;

	// current scrollbar positions
	int x_scrollbar_pos = 0;
	int y_scrollbar_pos = 0;

	// program scrollbar pos
	int program_scrollbar_pos = 0;

	// size of the rendered area
	int render_width;
	int render_height;

	// currently selected amount of repetitions
	int m_repititions = 1; //TODO change default value

	// character limit for current program display
	int m_max_commands_in_lineedit;

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

