#include "renderwidget.h"

#include <iostream>

#include <qpainter.h>

RenderWidget::RenderWidget(QWidget *parent)
	: QWidget(parent)
{
}

// get a gamecontroller reference from passed from MainWindow
void RenderWidget::set_game_controller_ref(
	std::shared_ptr<GameController> p_game_controller)
{
	m_game_controller_ref = p_game_controller;
}

void RenderWidget::render()
{
	// get refernce to the current colony
	Colony& temp_colony = m_game_controller_ref->get_current_colony();

	// create painter for drawing on the renderwidget
	QPainter painter(this);

	// local variable for the dimensions the tiles are in
	int tile_size = 32;

	// all X and Y offsets and dimensions needed for rendering:

	// create "local" variables for the x and y scrollbar position and the
	// render width and height in pixels
	int x_scrollbar_pos         = m_game_controller_ref->get_x_scrollbar_pos();
	int render_width_in_pixels  = m_game_controller_ref->get_render_width();
	int y_scrollbar_pos         = m_game_controller_ref->get_y_scrollbar_pos();
	int render_height_in_pixels = m_game_controller_ref->get_render_height();

	// calculate x and y tile where the rendering should start
	int x_start_tile = (x_scrollbar_pos -
					    (x_scrollbar_pos % tile_size)) / tile_size;
	int y_start_tile = (y_scrollbar_pos -
						(y_scrollbar_pos % tile_size)) / tile_size;

	// the number of tiles which get rendered in x-direction
	int x_tiles_to_rendered;
	// initialize x_tiles_to_rendered
	if (render_width_in_pixels % tile_size == 0)
	{
		// if the render_height_in_pixels divides by tile_size then just devide
		// it by tile_size for the amount of tiles to be rendered
		x_tiles_to_rendered = render_width_in_pixels / tile_size;
	}
	else
	{
		// if does not fit exactly then divide it by tile_size round down
		// and add +1 because the minus modulo cuts one of and +1 for filling
		// the screen so it is basicly the above + 1
		x_tiles_to_rendered =
			((render_width_in_pixels -(render_width_in_pixels % tile_size))
			/ tile_size) + 2;
	}

	// the number of tiles which get rendered in y-direction
	int y_tiles_to_rendered;
	// initialize y_tiles_to_rendered
	if (render_height_in_pixels % tile_size == 0)
	{
		// if the render_height_in_pixels divides by tile_size then just devide
		// it by tile_size for the amount of tiles to be rendered
		y_tiles_to_rendered = render_height_in_pixels / tile_size;
	}
	else
	{
		// if does not fit exactly then divide it by tile_size round down
		// and add +1 because the minus modulo cuts one of and +1 for filling
		// the screen so it is basicly the above + 1
		y_tiles_to_rendered =
			((render_height_in_pixels - (render_height_in_pixels % tile_size))
			/ tile_size) + 2;
	}

	// calculate the amount of offset needed to enable smooth pixel scrolling
	int x_pixel_offset = (x_scrollbar_pos % 32) * -1;
	int y_pixel_offset = (y_scrollbar_pos % 32) * -1;


	// render ground tiles
	for (int x = 0; x < x_tiles_to_rendered; x++)
	{
		for (int y = 0; y < y_tiles_to_rendered; y++)
		{
			// if coordinates are beyond the environment skip them
			// this happends for right and bottom boundaries
			if (x + x_start_tile >= temp_colony.get_width() ||
				y + y_start_tile >= temp_colony.get_height())
			{
				continue;
			}
			// get a ref to the tile which gets rendered next
			const Tile& temp_tile = temp_colony.get_tile_by_coordinates(
				x + x_start_tile, y + y_start_tile);

			// load matching QImage for current tile from controller
			const std::shared_ptr<QImage> current_tile_image =
				m_game_controller_ref->
					get_ground_texture_by_tile_type(temp_tile.get_tile_type());

			// calculate the x and y where the current tile should be rendered
			int x_render_offset = tile_size * x + x_pixel_offset;
			int y_render_offset = tile_size * y + y_pixel_offset;
			
			// draw the QImage at the earlier calculated coordinates
			painter.drawImage(
				QPoint(x_render_offset, y_render_offset), *current_tile_image);
		}
	}

	
	// render robots on top
	const std::vector<Robot>& temp_robots = temp_colony.get_robots();
	
	for (const Robot& temp_robot : temp_robots)
	{
		if (temp_robot.get_robot_type() == RobotType::PATCHBOT &&
			m_game_controller_ref->get_game_state() ==
			GameState::GAME_NOT_STARTED)
		{
			continue;
		}

		// get the robots position in tiles
		int robot_x_tile = temp_robot.get_x_coordinate();
		int robot_y_tile = temp_robot.get_y_coordinate();

		// check if the robot tile coordinates are within the rendered tiles
		if (robot_x_tile >= x_start_tile &&
			robot_x_tile <  x_start_tile + x_tiles_to_rendered &&
			robot_y_tile >= y_start_tile &&
			robot_y_tile <  y_start_tile + y_tiles_to_rendered)
		{
			// load matching QImage for current robot from controller
			const std::shared_ptr<QImage> current_tile_image =
				m_game_controller_ref->
					get_robot_texture_by_robot_type(
						temp_robot.get_robot_type());
			
			// calculate render_offset from 0,0
			int x_render_coordinate = (robot_x_tile - x_start_tile) * tile_size
									   + x_pixel_offset;
			int y_render_coordinate = (robot_y_tile - y_start_tile) * tile_size
									   + y_pixel_offset;

			// render the the QImage at the calcualted offset
			painter.drawImage(
				QPoint(x_render_coordinate, y_render_coordinate),
				*current_tile_image);
		}
	}
}

void RenderWidget::paintEvent(QPaintEvent * event)
{
	// if a colony is loaded, render it
	if (m_game_controller_ref->colony_loaded())
	{
		render();
	}
}