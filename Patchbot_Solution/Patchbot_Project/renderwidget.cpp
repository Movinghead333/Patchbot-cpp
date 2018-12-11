#include "renderwidget.h"

#include <iostream>

#include <qpainter.h>

RenderWidget::RenderWidget(QWidget *parent)
	: QWidget(parent)
{
}

RenderWidget::~RenderWidget()
{
}

void RenderWidget::set_game_controller_ref(
	std::shared_ptr<GameController> p_game_controller
)
{
	m_game_controller_ref = p_game_controller;
}

void RenderWidget::render()
{
	//std::cout << m_game_controller_ref->get_x_scrollbar_pos() << std::endl;
	// get refernce to the current colony
	const Colony& temp_colony = m_game_controller_ref->get_current_colony();

	// create painter for drawing on the renderwidget
	QPainter painter(this);


	// all X and Y offsets and dimensions needed for rendering:

	// create "local" variables for the x and y scrollbar position and the
	// render width and height in pixels
	int x_scrollbar_pos = m_game_controller_ref->get_x_scrollbar_pos();
	int render_width_in_pixels = m_game_controller_ref->get_render_width();
	int y_scrollbar_pos = m_game_controller_ref->get_y_scrollbar_pos();
	int render_height_in_pixels = m_game_controller_ref->get_render_height();

	// calculate x tile where the rendering should start
	int x_start_tile = (x_scrollbar_pos - (x_scrollbar_pos % 32)) / 32;
	int y_start_tile = (y_scrollbar_pos - (y_scrollbar_pos % 32)) / 32;

	// the number of tiles which get rendered in x-direction
	int x_tiles_to_rendered;
	// initialize x_tiles_to_rendered
	if (render_width_in_pixels % 32 == 0)
	{
		// if the render_width_in_pixels divides by 32 just devide it by 32
		// for the amount of tiles to be rendered
		x_tiles_to_rendered = render_width_in_pixels / 32;
	}
	else
	{
		// if does not fit exactly then divide it by 32 round down
		// and add +1 because the minus modulo cuts one of and +1 for filling
		// the screen so it is basicly the above + 1
		x_tiles_to_rendered =
		((render_width_in_pixels - (render_width_in_pixels % 32)) / 32) + 2;
	}

	// the number of tiles which get rendered in y-direction
	int y_tiles_to_rendered;
	// initialize y_tiles_to_rendered
	if (render_height_in_pixels % 32 == 0)
	{
		// if the render_height_in_pixels divides by 32 just devide it by 32
		// for the amount of tiles to be rendered
		y_tiles_to_rendered = render_height_in_pixels / 32;
	}
	else
	{
		// if does not fit exactly then divide it by 32 round down
		// and add +1 because the minus modulo cuts one of and +1 for filling
		// the screen so it is basicly the above + 1
		y_tiles_to_rendered =
		((render_height_in_pixels - (render_height_in_pixels % 32)) / 32) + 2;
	}

	// calculate the amount of offset needed to enable smooth pixel scrolling
	int x_pixel_offset = (x_scrollbar_pos % 32) * -1;
	int y_pixel_offset = (y_scrollbar_pos % 32) * -1;


	// render ground tiles
	for (int x = 0; x < x_tiles_to_rendered; x++)
	{
		for (int y = 0; y < y_tiles_to_rendered; y++)
		{
			if (x + x_start_tile >= temp_colony.get_width() ||
				y + y_start_tile >= temp_colony.get_height())
			{
				continue;
			}
			const Tile& temp_tile = temp_colony.get_tile_by_coordinates(
				x + x_start_tile, y + y_start_tile);

			const Texture& temp_texture =
				m_game_controller_ref->get_ground_texture_by_tile_type(
					temp_tile.get_tile_type()
				);

			const std::vector<ubyte>& temp_image_data =
				temp_texture.get_image_data();

			
			QImage current_tile_image(
				&temp_image_data[0],
				temp_texture.get_width(),
				temp_texture.get_height(),
				QImage::Format_ARGB32);
			
			painter.drawImage(
				QPoint(temp_texture.get_width()	 * x + x_pixel_offset,
					   temp_texture.get_height() * y + y_pixel_offset ),
				current_tile_image);
				
		}
	}

	
	// render robots on top
	std::vector<Robot>& temp_robots = temp_colony.get_enemy_robots();
	
	for (Robot temp_robot : temp_robots)
	{
		int robot_x_tile = temp_robot.get_x_coordinate();
		int robot_y_tile = temp_robot.get_y_coordinate();
		std::cout << robot_x_tile << "  " << robot_y_tile << std::endl;
		std::cout << temp_robot.get_robot_type() << std::endl;

		
		// check if the robot tile coordinates are within the rendered tiles
		if (robot_x_tile >= x_start_tile &&
			robot_x_tile < x_start_tile + x_tiles_to_rendered &&
			robot_y_tile >= y_start_tile &&
			robot_y_tile < y_start_tile + y_tiles_to_rendered)
		{
			// robot is in the area which is being rendered so render him too

			// get robot texture
			const Texture& temp_texture =
				m_game_controller_ref->get_robot_texture_by_robot_type(
					temp_robot.get_robot_type()
				);

			// get data vector from texture
			const std::vector<ubyte>& temp_image_data =
				temp_texture.get_image_data();

			// convert the image data into QImage object
			QImage current_tile_image(
				&temp_image_data[0],
				temp_texture.get_width(),
				temp_texture.get_height(),
				QImage::Format_ARGB32);
			
			int x_render_coordinate = (robot_x_tile - x_start_tile) * 32
									   + x_pixel_offset;
			int y_render_coordinate = (robot_y_tile - y_start_tile) * 32
									   + y_pixel_offset;

			// draw the QImage object at the robots position
			painter.drawImage(
				QPoint(x_render_coordinate, y_render_coordinate),
				current_tile_image);
			
		}
		
	}
}


void RenderWidget::paintEvent(QPaintEvent * event)
{
	if (m_game_controller_ref->colony_loaded())
	{
		render();
	}


	/*
	std::cout << "render area" << std::endl;
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;
	path.addRoundedRect(QRectF(10, 10, 100, 50), 10, 10);
	QPen pen(Qt::black, 10);
	p.setPen(pen);
	p.fillPath(path, Qt::red);
	p.drawPath(path);
	*/
}