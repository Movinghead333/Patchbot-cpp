#pragma once

#include <QWidget>

#include "gamecontroller.h"

class RenderWidget : public QWidget
{
	Q_OBJECT

public:
	RenderWidget(QWidget *parent = 0);
	~RenderWidget();

	void set_game_controller_ref(
		std::shared_ptr<GameController> p_game_controller
	);

	void render();

protected:
	void paintEvent(QPaintEvent *event) override;

private:
	std::shared_ptr<GameController> m_game_controller_ref;
};
