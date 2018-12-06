#include "renderwidget.h"

#include <iostream>

RenderWidget::RenderWidget(QWidget *parent)
	: QWidget(parent)
{
}

RenderWidget::~RenderWidget()
{
}

void RenderWidget::paintEvent(QPaintEvent * event)
{
	std::cout << "render area" << std::endl;
}
