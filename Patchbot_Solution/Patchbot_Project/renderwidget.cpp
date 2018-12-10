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
	std::cout << m_game_controller_ref->get_x_scrollbar_pos() << std::endl;
	const Colony& temp_colony = m_game_controller_ref->get_current_colony();
	QPainter painter(this);

	int x_scrollbar_pos = m_game_controller_ref->get_x_scrollbar_pos();

	int x_start_tile = (x_scrollbar_pos - (x_scrollbar_pos % 32)) / 32;

	int render_width_in_pixels = m_game_controller_ref->get_render_width();

	int x_tiles_to_rendered;
	if (render_width_in_pixels % 32 == 0)
	{
		x_tiles_to_rendered = render_width_in_pixels / 32;
	}
	else
	{
		x_tiles_to_rendered =
			((render_width_in_pixels - (render_width_in_pixels % 32)) / 32) + 2;
	}

	int x_pixel_offset = (x_scrollbar_pos % 32) * -1;
	//int render_width_in_tiles =

	// static render
	for (int x = 0; x < x_tiles_to_rendered; x++)
	{
		for (int y = 0; y < temp_colony.get_height(); y++)
		{
			if (x + x_start_tile >= temp_colony.get_width())
			{
				break;
			}
			const Tile& temp_tile = temp_colony.get_tile_by_coordinates(
				x_start_tile + x, y);

			const Texture& temp_texture =
				m_game_controller_ref->get_ground_texture_by_tile_type(
					temp_tile.get_tile_type()
				);

			const std::vector<ubyte>& temp_image_data =
				temp_texture.get_image_data();

			//std::cout << temp_image_data.size() << std::endl;
			
			QImage current_tile_iamge(
				&temp_image_data[0],
				temp_texture.get_width(),
				temp_texture.get_width(),
				QImage::Format_ARGB32);
			
			painter.drawImage(
				QPoint(temp_texture.get_width() * x + x_pixel_offset,
					   temp_texture.get_height() * y),
				current_tile_iamge);
				
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
