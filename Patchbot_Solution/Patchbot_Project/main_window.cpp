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


	try
	{
		// create Gamecontroller for data and game-logic management
		m_game_controller = std::make_shared<GameController>(GameController());
	}
	catch (const Simple_Message_Exception& exception)
	{
		// catch errors, which occured during image loading
		std::cerr << exception.m_error_message << std::endl;

		display_error_message_dialog("Error loading textures:",
									 exception.m_error_message);
	}
	

	// add refernce of gamecontroller to rendering widget
	ui.game->set_game_controller_ref(m_game_controller);

	// connect scrollbars
	connect(ui.xScrollbar, SIGNAL(valueChanged(int)),
		this, SLOT(scroll_x(int)));
	connect(ui.yScrollbar, SIGNAL(valueChanged(int)),
		this, SLOT(scroll_y(int)));
	connect(ui.scrollProgram, SIGNAL(valueChanged(int)),
		this, SLOT(scroll_program(int)));

	// connect dropdown
	connect(ui.repititionComboBox, SIGNAL(currentTextChanged(QString)),
		this, SLOT(repititions_changed(QString)));
}

void MainWindow::paintEvent(QPaintEvent *)
{
	
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
	calculate_render_details();
}


// slots for programming buttons
void MainWindow::on_directionUp_clicked()
{
	m_game_controller->add_move_to_current_program(MoveType::UP);
	update_program_scroll_max();
}

void MainWindow::on_directionRight_clicked()
{
	m_game_controller->add_move_to_current_program(MoveType::RIGHT);
	update_program_scroll_max();
}

void MainWindow::on_directionDown_clicked()
{
	m_game_controller->add_move_to_current_program(MoveType::DOWN);
	update_program_scroll_max();
}

void MainWindow::on_directionLeft_clicked()
{
	m_game_controller->add_move_to_current_program(MoveType::LEFT);
	update_program_scroll_max();
}

void MainWindow::on_removeCommand_clicked()
{
	try
	{
		m_game_controller->remove_most_recently_added_move();
		update_program_scroll_max();
	}
	catch (const Simple_Message_Exception& exception)
	{
		display_error_message_dialog("An error occured:",
									 exception.m_error_message);
	}
}

void MainWindow::on_playerWait_clicked()
{
	try
	{
		m_game_controller->add_move_to_current_program(MoveType::WAIT);
		update_program_scroll_max();
	}
	catch (const Simple_Message_Exception& exception)
	{
		display_error_message_dialog("An error occured:",
									 exception.m_error_message);
	}
}

// slots for mission control buttons
void MainWindow::on_missionStart_clicked()
{
	m_game_controller->display_current_program();
	//display_info_message_dialog("Mission-start button clicked!");
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
		calculate_render_details();
	}
	// catch all specified exceptions
	catch (const Simple_Message_Exception& e)
	{
		std::cerr << e.m_error_message << std::endl;
		display_error_message_dialog("Error occured during map loading:",
									 e.m_error_message);
	}
	// catch any non aticipated exceptions
	catch (...)
	{
		std::cout << "Unchecked exception thrown" << std::endl;
	}
}

// dropdown slot for program repititions
void MainWindow::repititions_changed(const QString & p_new_text)
{
	m_game_controller->set_m_repititions(p_new_text);
}

// scrollbar slots
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

void MainWindow::scroll_program(int p_new_value)
{
	m_game_controller->set_program_scrollbar_pos(p_new_value);
	// TODO add current text to display
	QString temp_str = "";
	
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

void MainWindow::display_error_message_dialog(const std::string& p_title,
	const std::string& p_message)
{
	QMessageBox::critical(
		this,
		p_title.c_str(),
		p_message.c_str());
}

// adjust scrollbars and calculate render area dimensions
void MainWindow::calculate_render_details()
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

	// add resizing for current program scrollbar

		// get max character width of the line edit's font
//	int maxWidth = QFontMetrics(ui.currentProgramText->font()).
//			maxWidth();

	// find the character limit based on the max width and send it to the
	// controller
	m_game_controller->set_m_max_commands_in_lineedit(
		ui.currentProgramText->width() / 30);
	std::cout << "max chars for current program" << std::endl;
	std::cout << ui.currentProgramText->width() / 30 << std::endl;
	update_program_scroll_max();
}

void MainWindow::update_program_scroll_max()
{
	ui.scrollProgram->setMaximum(
		m_game_controller->calcualte_program_scrollbar_max());
}
