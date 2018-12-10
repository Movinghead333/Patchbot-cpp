#include "main_window.h"

#include <qmessagebox.h>
#include <qfiledialog.h>

#include "src/colony.h"

// constructor initializing the window
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	
	this->setWindowTitle("PATCHBOT v1.0");

	// create Gamecontroller for data and game-logic management
	m_game_controller = std::make_shared<GameController>(GameController());

	// add refernce of gamecontroller to rendering widget
	ui.game->set_game_controller_ref(m_game_controller);

	// connect scrollbars
	connect(ui.xScrollbar, SIGNAL(valueChanged(int)),
		this, SLOT(scroll_x(int)));
	connect(ui.yScrollbar, SIGNAL(valueChanged(int)),
		this, SLOT(scroll_y(int)));
}

// destructor
MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
	
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
	if (m_game_controller->colony_loaded()) {
		// get ref of current colony
		const Colony& current_colony = m_game_controller->get_current_colony();

		// get the width and height of the entire map in pixels
		int map_width = current_colony.get_width() * 32;
		int map_height = current_colony.get_height() * 32;

		// get dimensions of the game widget
		int render_width = ui.game->width();
		int render_height = ui.game->height();

		// max values for scrollbars
		int m_scroll_x_max;
		int m_scroll_y_max;


		// X direction
		if (render_width >= map_width)
		{
			m_scroll_x_max = 0;
		}
		else
		{
			m_scroll_x_max = map_width - render_width;
		}

		// Y direction
		if (render_height >= map_height)
		{
			m_scroll_y_max = 0;
		}
		else
		{
			m_scroll_y_max = map_height - render_height;
		}
		ui.xScrollbar->setMaximum(m_scroll_x_max);
		ui.yScrollbar->setMaximum(m_scroll_y_max);
		m_game_controller->set_render_width(ui.game->width());
		m_game_controller->set_render_height(ui.game->height());
	}

	
}


// slots for programming buttons
void MainWindow::on_directionUp_clicked()
{
	display_info_message_dialog("Up direction button clicked!");
}

void MainWindow::on_directionRight_clicked()
{
	display_info_message_dialog("Right direction button clicked!");
}

void MainWindow::on_directionDown_clicked()
{
	display_info_message_dialog("Down direction button clicked!");
}

void MainWindow::on_directionLeft_clicked()
{
	display_info_message_dialog("Left direction button clicked!");
}

void MainWindow::on_removeCommand_clicked()
{
	display_info_message_dialog("Remove command button clicked!");
}

void MainWindow::on_playerWait_clicked()
{
	display_info_message_dialog("Wait button clicked!");
}

// slots for mission control buttons
void MainWindow::on_missionStart_clicked()
{
	display_info_message_dialog("Mission-start button clicked!");
}

void MainWindow::on_missionCancel_clicked()
{
	display_info_message_dialog("Mission-cancel button clicked!");
}

void MainWindow::on_missionStep_clicked()
{
	display_info_message_dialog("MIssion-step button clicked!");
}

void MainWindow::on_missionAutomatic_clicked()
{
	display_info_message_dialog("Mission-automatic button clicked!");
}

void MainWindow::on_missionPause_clicked()
{
	display_info_message_dialog("Mission-pause button clicked!");
}

// changing colony
void MainWindow::on_changeColony_clicked()
{
	QString filter = "Textfile (*.txt)";

	std::string file_name = QFileDialog::getOpenFileName(
		this, "Open new Colony", "C://", filter
	).toStdString();

	try
	{
		m_game_controller->load_and_initialize_colony(file_name);
	}
	// catch all specified exceptions
	catch (const Simple_Message_Exception& e)
	{
		std::cerr << e.m_error_message << std::endl;
	}
	// catch any non aticipated exceptions
	catch (...)
	{
		std::cout << "Unchecked exception thrown" << std::endl;
	}
}

void MainWindow::scroll_x(int p_new_value)
{
	m_game_controller->set_x_scrollbar_pos(p_new_value);
	ui.game->update();
}

void MainWindow::scroll_y(int p_new_value)
{
	m_game_controller->set_y_scrollbar_pos(p_new_value);
	ui.game->update();
}

// shows short information dialog displaying that a button has been clicked
// and message which button has been pressed (p_message)
void MainWindow::display_info_message_dialog(const std::string& p_message)
{
	QMessageBox::information(
		this,
		"Button clicked",
		p_message.c_str());
}