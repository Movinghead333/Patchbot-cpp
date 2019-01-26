#include "gamecontroller.h"


// loads textures into memory and initializes the current program vector
GameController::GameController()
{
	// load images into controller
	// throws Simple_Message_Exception which is caught in MainWindow
	load_textures();
	m_current_program = std::vector<PatchbotMove>();
}

// loads a colony from a given filepath into memory and resets the current
// program vector
void GameController::load_and_initialize_colony(
	const std::string& p_file_path)
{
	// load a colony from file into controller
	m_current_colony = std::make_shared<Colony>(
		*Colony::load_colony(p_file_path));

	// reset the patchbot program
	m_current_program = std::vector<PatchbotMove>();
}

// loads all needed textures into memory for later rendering
void GameController::load_textures()
{
	// load ground textures
	// setup path-variables
	std::string ground_texture_base_path = "src\\textures\\umgebungen\\";

	// temp map to link paths to TileTypes
	std::map<TileType, std::string> tile_paths;

	tile_paths.insert(
		std::make_pair(
			TileType::STEELPLANKS, "boden.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::PATCHBOT_SPAWN, "boden_start_patchbot.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ENEMY_SPAWN, "boden_start_gegner.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ABYSS, "gefahr_abgrund.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::WATER, "gefahr_wasser.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ROOT_SERVER, "hauptserver.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::ALIEN_GRASS, "hindernis_aliengras.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::GRAVEL, "hindernis_schotter.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::SECRET_ENTRANCE, "hindernis_geheimgang.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::MANUAL_DOOR_OPEN, "tuer_manuell_offen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::MANUAL_DOOR_CLOSED, "tuer_manuell_geschlossen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::AUTO_DOOR_OPEN, "tuer_automatisch_offen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::AUTO_DOOR_CLOSED, "tuer_automatisch_geschlossen.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::INDESTRUCTABLE_WALL, "wand_beton.tga"));
	tile_paths.insert(
		std::make_pair(
			TileType::DESTRUCTABLE_WALL, "wand_fels.tga"));
		

	// load the textures into the map
	m_ground_textures = std::map<TileType, std::shared_ptr<QImage>>();

	for (const std::pair<TileType, std::string>& resource_pair : tile_paths)
	{
		const Texture temp_texture = Texture::load_texture(
			(ground_texture_base_path + resource_pair.second));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into a shared_ptr and then insert it 
		// with a matching TileType key
		m_ground_textures.insert(
			std::pair<TileType, std::shared_ptr<QImage>>(
				resource_pair.first,
				std::make_shared<QImage>(
					temp_image.mirrored(false, true).copy()
				) 
			)
		);
	}


	// load robot textures
	// setup path-variables
	std::string robot_texture_base_path = "src\\textures\\roboter\\";

	std::map<RobotType, std::string> robot_resource_map;

	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::PATCHBOT, "patchbot.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::BUGGER,   "typ1_bugger.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::PUSHER,   "typ2_pusher.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::DIGGER,   "typ3_digger.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::SWIMMER,  "typ4_swimmer.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::FOLLOWER, "typ5_follower.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::HUNTER,   "typ6_hunter.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::SNIFFER,  "typ7_sniffer.tga"));
	robot_resource_map.insert(
		std::make_pair<RobotType, std::string>(
			RobotType::DEAD,     "dead.tga"));


	// create and fill the map with the robot images
	m_robot_textures = std::map<RobotType, std::shared_ptr<QImage>>();

	// calculate length of robot_type enum and load all robot images
	for (const std::pair<RobotType, std::string>& resource : robot_resource_map)
	{
		const Texture temp_texture = Texture::load_texture(
			(robot_texture_base_path + resource.second));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into the vector
		m_robot_textures.insert(
			std::pair<RobotType, std::shared_ptr<QImage>>(
				resource.first,
				std::make_shared<QImage>(
					temp_image.mirrored(false, true).copy()
				)
			)
		);
	}

	// load arrows for dijkstra algorithm debugging
	std::string arrows_texture_base_path = "src\\textures\\pfeile\\";

	std::map<BestPath, std::string> arrow_resource_map;

	arrow_resource_map.insert(
		std::make_pair<BestPath, std::string>(
			BestPath::PATH_UP, "pfeil_oben.tga"));
	arrow_resource_map.insert(
		std::make_pair<BestPath, std::string>(
			BestPath::PATH_RIGHT, "pfeil_rechts.tga"));
	arrow_resource_map.insert(
		std::make_pair<BestPath, std::string>(
			BestPath::PATH_DOWN, "pfeil_unten.tga"));
	arrow_resource_map.insert(
		std::make_pair<BestPath, std::string>(
			BestPath::PATH_LEFT, "pfeil_links.tga"));

	for (const std::pair<BestPath, std::string>& resource :
			arrow_resource_map)
	{
		const Texture temp_texture = Texture::load_texture(
			(arrows_texture_base_path + resource.second));

		// get the textures image data as ref
		const std::vector<ubyte>& temp_image_data =
			temp_texture.get_image_data();

		// convert the image-data into a QImage
		QImage temp_image(
			&temp_image_data[0],
			temp_texture.get_width(),
			temp_texture.get_height(),
			QImage::Format_ARGB32);

		// mirror the image and copy it into the vector
		m_arrow_textures.insert(
			std::pair<BestPath, std::shared_ptr<QImage>>(
				resource.first,
				std::make_shared<QImage>(
					temp_image.mirrored(false, true).copy()
					)
				)
		);
	}
}

// return a editable reference to the current colony
Colony& GameController::get_current_colony()
{
	return *m_current_colony.get();
}

// checks if there is a colony loaded into the game
bool GameController::colony_loaded() const
{
	return m_current_colony != nullptr;
}

// adds a command to current program based on the selected MoveType and the 
// selected repititions
// throws if Move is "wait until obstacle"
void GameController::add_move_to_current_program(MoveType p_move_type)
{
	if (m_repititions == -1 && p_move_type == MoveType::WAIT)
	{
		throw Simple_Message_Exception("Cannot add command \"wait until "
			"obstacle\"");
	}
	else
	{
		m_current_program.push_back(PatchbotMove(m_repititions, p_move_type));
	}
}

// calculates the current string to be displayed by the current program
// lineedit and returns it
const QString GameController::get_currently_displayed_program_string() const
{
	QString temp_string = "";

	int iterations = m_max_commands_in_lineedit;
	if (m_max_commands_in_lineedit > m_current_program.size())
	{
		iterations = m_current_program.size();
	}

	for (int i = 0; i < iterations; i++)
	{
		// todo fix digit display
		int temp_pos = program_scrollbar_pos + i;
		const PatchbotMove& temp_move = m_current_program[temp_pos];
		temp_string.append(temp_move.m_move_type);
		if (temp_move.m_steps != -1)
		{
			temp_string.append(QString::number(temp_move.m_steps));
		}
		else
		{
			temp_string.append('X');
		}
	}
	return temp_string;
}

// controller method for removing the most recently added command
// throws exception if the program is already emtpy
void GameController::remove_most_recently_added_move()
{
	if (m_current_program.size() > 0)
	{
		m_current_program.pop_back();
	}
	else
	{
		throw Simple_Message_Exception("Cannot remove command from empty "
			"program!");
	}
}

// debug method for printing the current program to console
void GameController::display_current_program() const
{
	std::cout << "Current program:" << std::endl;
	for (int i = 0; i < m_current_program.size(); i++)
	{
		std::cout << (char)m_current_program[i].m_move_type << ": ";
		std::cout << m_current_program[i].m_steps			<< std::endl;
	}
}

// calculates the maximum for the program scrollbar depending on program length
// as well as available render space
int GameController::calcualte_program_scrollbar_max() const
{
	int temp_max_scroll = m_current_program.size() -
						  m_max_commands_in_lineedit;

	if (temp_max_scroll > 0)
	{
		return temp_max_scroll;
	}
	else
	{
		return 0;
	}
}

// checks if the current program is not empty
// if the current program is empty throw an exception
void GameController::validate_current_program() const
{
	if (m_current_program.size() == 0)
	{
		throw Simple_Message_Exception("Cannot start with empty program!");
	}
}

// starts the current program
void GameController::start_current_program()
{
	m_program_index = 0;
	m_current_move = m_current_program[m_program_index];
	set_game_state(GameState::IN_PROGRESS);

	// initial nav_mesh generation
	m_current_colony->generate_nav_mesh();
}

void GameController::execute_single_step()
{
	Patchbot& patchbot_ref = m_current_colony->get_patch_bot();

	// check if patchbot is blocked from aliengrass
	if (patchbot_ref.get_m_blocked())
	{
		patchbot_ref.set_m_blocked(false);
		return;
	}

	int current_x = patchbot_ref.get_x_coordinate();
	int current_y = patchbot_ref.get_y_coordinate();

	// do current step
	switch (m_current_move.m_move_type)
	{
	case MoveType::UP:
		current_y--;
		break;

	case MoveType::RIGHT:
		current_x++;
		break;

	case MoveType::DOWN:
		current_y++;
		break;

	case MoveType::LEFT:
		current_x--;
		break;

	case MoveType::WAIT:
		break;
	}

	// get a const ref to the current target tile
	const Tile& target_tile = m_current_colony->
		get_tile_by_coordinates(current_x, current_y);

	// check if the target tile is occupied
	bool occupied = target_tile.get_occupied();

	// check if the current movetype is a direction if so check if patchbot
	// needs to be moved
	if (m_current_move.m_move_type != MoveType::WAIT)
	{
		// if this is true the target field is no wall
		if (calculate_collision(current_x, current_y))
		{
			// if this is true the target_tile is occupied by another robot
			if (occupied)
			{
				if (m_current_move.m_steps != -1)
				{
					Point2D enemy_target_pos = Point2D(current_x, current_y);
					switch (m_current_move.m_move_type)
					{
					case UP:
						enemy_target_pos.y--;
						break;
					case RIGHT:
						enemy_target_pos.x++;
						break;
					case DOWN:
						enemy_target_pos.y++;
						break;
					case LEFT:
						enemy_target_pos.x--;
						break;
					}
					Tile& enemy_target_tile = m_current_colony->
						get_editable_tile_ref_by_coordinates(
							enemy_target_pos.x, enemy_target_pos.y);

					std::shared_ptr<Robot>& target_robot = m_current_colony->
						get_robot_by_id(target_tile.get_robot_id());

					// the target tile neither a wall nor blocked by another
					// robot thus patchbot can move the enemy robot
					if (target_robot->check_collision(enemy_target_tile) &&
						!enemy_target_tile.get_occupied())
					{
						// first move the enemy robot
						m_current_colony->move_robot_on_map(*target_robot,
							enemy_target_pos);

						// then move patchbot
						m_current_colony->move_robot_on_map(patchbot_ref,
							Point2D(current_x, current_y));

						// update the nav_mesh for the AI
						m_current_colony->generate_nav_mesh();
					}
				}
			}
			// else means the tile is free so patchbot can make its move
			else
			{
				//move the player
			//patchbot_ref.update_position(Point2D(current_x, current_y));
				m_current_colony->move_robot_on_map(
					patchbot_ref, Point2D(current_x, current_y));

				// update the nav_mesh for the AI
				m_current_colony->generate_nav_mesh();
			}
		}
		// else the target tile is wall so dont move
	}

	// if the repitions amount is set to go until obstacle then check if there
	// was an obstacle at the current step if so increment steps from -1 to 0 
	// so the program progresses to the next move
	// NOTE: the current implementation does an extra step to confirm the next
	//		 tile would be an obstacle
	if (m_current_move.m_steps == -1 &&
		(!calculate_collision(current_x, current_y) ||
			occupied))
	{
		m_current_move.m_steps++;
	}
	// if repititions is different from -1 then just decreasen it each step
	// until it reaches 0
	else if (m_current_move.m_steps > 0)
	{
		m_current_move.m_steps--;
	}

	// if the current index is equal to program-vectors size than the program
	// is finished
	if (m_current_move.m_steps == 0)
	{
		m_program_index++;
		if (m_program_index >= m_current_program.size())
		{
			if (m_game_state == GameState::IN_PROGRESS)
			{
				m_game_state = GameState::PROGRAM_ENDED;
			}
		}
		else
		{
			m_current_move = m_current_program[m_program_index];
		}
	}

	// update all robots
	for (std::shared_ptr<Robot>& robot : m_current_colony->get_robots())
	{
		robot->update(*m_current_colony);
		update_game_state();
	}
	//m_current_colony->print_robot_id_matrix();
	m_current_colony->print_occupiation_matrix();

	// update doors
	update_doors();
}

bool GameController::calculate_collision(int x, int y)
{
	// check the boundries if the move goes out of bounds return false
	if (x < 0 || x >= m_current_colony->get_width() ||
		y < 0 || y >= m_current_colony->get_height())
	{
		return false;
	}

	switch (m_current_colony->get_tile_by_coordinates(x, y).get_tile_type())
	{
	// true cases --> no collision
	case TileType::SECRET_ENTRANCE:
	case TileType::GRAVEL:
	case TileType::AUTO_DOOR_OPEN:
	case TileType::PATCHBOT_SPAWN:
	case TileType::ENEMY_SPAWN:
	case TileType::STEELPLANKS:
	case TileType::MANUAL_DOOR_OPEN:
		return true;
	case TileType::ALIEN_GRASS:
		m_current_colony->get_patch_bot().set_m_blocked(true);
		return true;
	case TileType::ABYSS:
		set_game_state(GameState::FELL_INTO_ABYSS);
		return true;
	case TileType::WATER:
		set_game_state(GameState::FELL_INTO_WATER);
		return true;

	// false cases --> collision
	case TileType::ROOT_SERVER:
		set_game_state(GameState::SERVER_REACHED);
		return false;
	case TileType::INDESTRUCTABLE_WALL:
	case TileType::DESTRUCTABLE_WALL:
	case TileType::AUTO_DOOR_CLOSED:
		return false;
	case TileType::MANUAL_DOOR_CLOSED:
		m_current_colony->get_editable_tile_ref_by_coordinates(x, y).
			set_m_tile_type(TileType::MANUAL_DOOR_OPEN);
		//TODO: decide wether a door takes one or 2 moves
		//m_current_move.m_steps++;
		return false;

	default: return false;
	}
}

void GameController::update_doors()
{
	std::vector<Door>& doors_ref = m_current_colony->get_doors();

	for (Door& temp_door : doors_ref)
	{
		Tile& temp_door_tile = get_editable_tile_ref_by_coordinates(
			temp_door.m_x, temp_door.m_y);
		temp_door.update(temp_door_tile);
	}
}

void GameController::reset_current_run()
{
	m_current_colony->reset_colony();
	set_game_state(GameState::GAME_NOT_STARTED);
	set_m_automatic_mode_enabled(false);
}

Tile& GameController::get_editable_tile_ref_by_coordinates(int p_x, int p_y)
{
	return m_current_colony->get_editable_tile_ref_by_coordinates(
		p_x, p_y);
}

void GameController::update_game_state()
{
	const Patchbot& patchbot = m_current_colony->get_patch_bot();

	const Point2D patchbot_pos = patchbot.get_position();

	const Tile& patchbot_tile = m_current_colony->
		get_tile_by_pos(patchbot_pos);

	const TileType patchbot_tile_type = patchbot_tile.get_tile_type();

	if (patchbot_tile_type == TileType::WATER)
	{
		m_game_state = GameState::FELL_INTO_WATER;
	}
	else if (patchbot_tile_type == TileType::ABYSS)
	{
		m_game_state = GameState::FELL_INTO_ABYSS;
	}
}

// image getters for retreiving image resources from controller
const std::shared_ptr<QImage> GameController::get_ground_texture_by_tile_type(
	const TileType & p_tile) const
{
	return m_ground_textures.find(p_tile)->second;
}

const std::shared_ptr<QImage> GameController::get_robot_texture_by_robot_type(
	const RobotType& p_robot_type) const
{
	return m_robot_textures.find(p_robot_type)->second;
}

const std::shared_ptr<QImage> GameController::get_arrow_texture_by_path_enum(
	const BestPath & p_best_path) const
{
	return m_arrow_textures.find(p_best_path)->second;
}

// getters and setters for scrollbars
void GameController::set_x_scrollbar_pos(int p_new_pos)
{
	x_scrollbar_pos = p_new_pos;
}

void GameController::set_y_scrollbar_pos(int p_new_pos)
{
	y_scrollbar_pos = p_new_pos;
}

void GameController::set_program_scrollbar_pos(int p_new_pos)
{
	program_scrollbar_pos = p_new_pos;
}

int GameController::get_x_scrollbar_pos() const
{
	return x_scrollbar_pos;
}

int GameController::get_y_scrollbar_pos() const
{
	return y_scrollbar_pos;
}

int GameController::get_program_scrollbar_pos() const
{
	return program_scrollbar_pos;
}

// getters and setters for render dimensions
void GameController::set_render_width(int p_new_width)
{
	render_width = p_new_width;
}

void GameController::set_render_height(int p_new_height)
{
	render_height = p_new_height;
}

int GameController::get_render_width() const
{
	return render_width;
}

int GameController::get_render_height() const
{
	return render_height;
}

// setter for command repititions
void GameController::set_m_repititions(QString p_combo_box_input)
{
	QChar current_value = p_combo_box_input[0];
	if (current_value == 'X')
	{
		m_repititions = -1;
	}
	else
	{
		m_repititions = current_value.toLatin1() - '0';
	}
}

// getter and setter for the number of commands display int current program
// line-edit
void GameController::set_m_max_commands_in_lineedit(int p_max_chars)
{
	m_max_commands_in_lineedit = p_max_chars;
}

int GameController::get_m_max_commands_in_lineedit() const
{
	return m_max_commands_in_lineedit;
}

// getter and setter for automatic mode flag
void GameController::set_m_automatic_mode_enabled(
	bool p_m_automatic_mode_enabled)
{
	m_automatic_mode_enabled = p_m_automatic_mode_enabled;
}

bool GameController::get_m_automatic_mode_enabled() const
{
	return m_automatic_mode_enabled;
}

GameState GameController::get_game_state() const
{
	return m_game_state;
}

void GameController::set_game_state(GameState p_game_state)
{
	m_game_state = p_game_state;
}
