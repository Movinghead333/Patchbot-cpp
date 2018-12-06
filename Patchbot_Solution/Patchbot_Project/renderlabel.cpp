#include "renderlabel.h"
#include <iostream>

RenderLabel::RenderLabel(QWidget *parent)
	: QLabel(parent)
{
}

RenderLabel::~RenderLabel()
{
}

void RenderLabel::paintEvent(QPaintEvent *event)
{
	std::cout << "label rendered" << std::endl;
}
