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

	const Colony& get_current_colony() const;

	bool colony_loaded() const;

	const Texture& get_ground_texture_by_tile_type(
		const TileType& p_tile) const;

	const Texture& get_robot_texture_by_robot(const RobotType& p_robot) const;

	// scrollbar getters and setters
	void set_x_scrollbar_pos(int p_new_pos);
	void set_y_scrollbar_pos(int p_new_pos);

	int get_x_scrollbar_pos();
	int get_y_scrollbar_pos();

	// scrollbar getters and setters
	void set_render_width(int p_new_width);
	void set_render_height(int p_new_height);

	int get_render_width();
	int get_render_height();

private:
	// current scrollbar positions
	int x_scrollbar_pos = 0;
	int y_scrollbar_pos = 0;

	// size of the rendered area
	int render_width;
	int render_height;

	// stores the currently displayed colony
	std::shared_ptr<Colony> m_current_colony;

	// stores all graphics for ground tiles
	std::shared_ptr<std::vector<Texture>> m_ground_textures;

	// stores all robot-graphics
	std::shared_ptr<std::vector<Texture>> m_robot_textures;
};

#endif

