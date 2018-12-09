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


void RenderWidget::paintEvent(QPaintEvent * event)
{
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
