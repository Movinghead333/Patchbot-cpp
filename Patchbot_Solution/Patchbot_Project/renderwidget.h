#pragma once

#include <QWidget>

class RenderWidget : public QWidget
{
	Q_OBJECT

public:
	RenderWidget(QWidget *parent = 0);
	~RenderWidget();

protected:
	void paintEvent(QPaintEvent *event) override;
};
