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
	const Colony& temp_colony = m_game_controller_ref->get_current_colony();
	QPainter painter(this);

	// static render
	for (int x = 0; x < temp_colony.get_width(); x++)
	{
		for (int y = 0; temp_colony.get_height(); y++)
		{
			const Tile& temp_tile = temp_colony.get_tile_by_coordinates(x, y);
			//Texture& temp_texture =
			//m_game_controller_ref.get_texture(temp_tile);
			//painter.drawImage(QImage(temp_tile.get_data()));
		}
	}
}


void RenderWidget::paintEvent(QPaintEvent * event)
{
	if (m_game_controller_ref->colony_loaded())
	{
		render();
	}
	std::cout << "render area" << std::endl;
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;
	path.addRoundedRect(QRectF(10, 10, 100, 50), 10, 10);
	QPen pen(Qt::black, 10);
	p.setPen(pen);
	p.fillPath(path, Qt::red);
	p.drawPath(path);
}
