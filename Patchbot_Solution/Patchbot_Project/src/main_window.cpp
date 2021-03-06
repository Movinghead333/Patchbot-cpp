#include "main_window.h"

#include <qmessagebox.h>
#include <qfiledialog.h>

#include "colony.h"

// constructor initializing the window
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// mission ui disabled by when starting up the game
	set_mission_ui_enabled(false);

	// programming ui is also disabled until a colony gets loaded
	set_programming_ui_enabled(false);

	this->setWindowTitle("PATCHBOT v1.0");

	m_automatic_mode_timer = std::make_shared<QTimer>(new QTimer(this));

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
	connect(ui.xScrollbar,	  SIGNAL(valueChanged(int)),
			this,			  SLOT(scroll_x(int)));
	connect(ui.yScrollbar,	  SIGNAL(valueChanged(int)),
			this,			  SLOT(scroll_y(int)));
	connect(ui.scrollProgram, SIGNAL(valueChanged(int)),
			this,			  SLOT(scroll_program(int)));

	// connect dropdown
	connect(ui.repititionComboBox, SIGNAL(currentTextChanged(QString)),
			this,				   SLOT(repititions_changed(QString)));

	// connect the timer for automatic mode
	connect(m_automatic_mode_timer.get(), SIGNAL(timeout()),
			this,					      SLOT(automatic_mode_step()));
}

void MainWindow::paintEvent(QPaintEvent *)
{
	
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
	calculate_render_details();
}

void MainWindow::set_programming_ui_enabled(bool enabled)
{
	ui.directionLeft->setEnabled(enabled);
	ui.directionRight->setEnabled(enabled);
	ui.directionUp->setEnabled(enabled);
	ui.directionDown->setEnabled(enabled);
	ui.playerWait->setEnabled(enabled);
	ui.removeCommand->setEnabled(enabled);
	ui.repititionComboBox->setEnabled(enabled);
}

void MainWindow::set_mission_ui_enabled(bool enabled)
{
	ui.missionAutomatic->setEnabled(enabled);
	ui.missionStep->setEnabled(enabled);
	ui.missionCancel->setEnabled(enabled);
	ui.missionStart->setEnabled(enabled);
	ui.missionPause->setEnabled(enabled);
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
	try
	{
		// validate the current program
		m_game_controller->validate_current_program();
		m_game_controller->start_current_program();

		//debug
		m_game_controller->display_current_program();

		// disabled programming interface
		set_programming_ui_enabled(false);

		// update mission control interface
		ui.missionStart->setEnabled(false);
		ui.missionAutomatic->setEnabled(true);
		ui.missionStep->setEnabled(true);
		ui.missionCancel->setEnabled(true);

		// update gamewindow
		ui.game->update();
	}
	catch (const Simple_Message_Exception& exception)
	{
		display_error_message_dialog("An error occured",
									 exception.m_error_message);
	}
}

void MainWindow::on_missionCancel_clicked()
{
	// reset the controller and ui for new program run
	reset_current_run_and_ui();
}

void MainWindow::on_missionStep_clicked()
{
	single_step();
}

void MainWindow::on_missionAutomatic_clicked()
{
	// disable step and automation button
	ui.missionAutomatic->setEnabled(false);
	ui.missionStep->setEnabled(false);

	// enable the pause button
	ui.missionPause->setEnabled(true);

	// set automatic mode to true
	m_game_controller->set_m_automatic_mode_enabled(true);

	// and start the timer
	m_automatic_mode_timer->start(1000);
}

void MainWindow::on_missionPause_clicked()
{
	// enable single step and automatic mode buttons
	ui.missionAutomatic->setEnabled(true);
	ui.missionStep->setEnabled(true);

	// disable pause button
	ui.missionPause->setEnabled(false);

	// set automatic mode to false
	m_game_controller->set_m_automatic_mode_enabled(false);

	// and stop the timer
	m_automatic_mode_timer->stop();
}

// changing colony
void MainWindow::on_changeColony_clicked()
{
	QString filter = "Textfile (*.txt)";
	QString q_file_name = QFileDialog::getOpenFileName(
		this, "Open new Colony", "C://", filter
	);

	

	std::string file_name = q_file_name.toStdString();

	try
	{
		m_game_controller->load_and_initialize_colony(file_name);

		// set the currently colony label
		QFileInfo file_info = QFileInfo(q_file_name);
		ui.staticColonyName->setText(
			QString("Aktuelle Kolonie: ") + file_info.baseName());

		calculate_render_details();
		set_programming_ui_enabled(true);
		ui.missionStart->setEnabled(true);
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
	// send new scrollbar position to controller
	m_game_controller->set_program_scrollbar_pos(p_new_value);

	// update current program textfield
	ui.currentProgramText->setText(
		m_game_controller->get_currently_displayed_program_string());
	
}

void MainWindow::automatic_mode_step()
{
	single_step();
	std::cout << "Single step in automation mode executed" << std::endl;
}

// shows short information dialog displaying that a button has been clicked
// and message which button has been pressed (p_message)
void MainWindow::display_info_message_dialog(const std::string& title,
	const std::string& p_message)
{
	QMessageBox::information(
		this,
		title.c_str(),
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
	int maxWidth = QFontMetrics(ui.currentProgramText->font()).
			maxWidth();

	maxWidth /= 2;

	// find the character limit based on the max width and send it to the
	// controller
	m_game_controller->set_m_max_commands_in_lineedit(
		(ui.currentProgramText->width() / maxWidth) - 2);
	std::cout << "max chars for current program" << std::endl;
	std::cout << (ui.currentProgramText->width() / maxWidth) - 2 << std::endl;
	update_program_scroll_max();
}

void MainWindow::update_program_scroll_max()
{
	ui.scrollProgram->setMaximum(
		m_game_controller->calcualte_program_scrollbar_max());
	ui.currentProgramText->setText(
		m_game_controller->get_currently_displayed_program_string());
}

void MainWindow::check_win_and_loose_conditions()
{
	if (m_game_controller->get_game_state() == GameState::IN_PROGRESS)
	{
		return;
	}

	std::string title = "Game lost!";
	std::string message;

	// generate dialog content
	switch (m_game_controller->get_game_state())
	{
	case GameState::PROGRAM_ENDED:
		message = "The program ended before patchbot reached a server. "
				  "Mission failed!";
		break;
	case GameState::FELL_INTO_ABYSS:
		message = "Patchbot fell into an abyss. Mission failed!";
		break;
	case GameState::FELL_INTO_WATER:
		message = "Patchbot fell into water. Mission failed!";
		break;
	case GameState::DESTROYED_BY_ROBOT:
		message = "Patchbot has been destroyed by another robot!";
		break;
	case GameState::SERVER_REACHED:
		title = "Game won!";
		message = "Patchbot reached a server. Mission successful!";
		break;
	}

	// display dialog
	display_info_message_dialog(title, message);

	// reset the controller and ui for new program run
	reset_current_run_and_ui();
}

void MainWindow::single_step()
{
	// execute a single time-step
	m_game_controller->execute_single_step();

	// update the game after the step
	ui.game->update();

	// check the win / loose conditions
	check_win_and_loose_conditions();
}

void MainWindow::reset_current_run_and_ui()
{
	// stop the timer if it still running
	if (m_game_controller->get_m_automatic_mode_enabled())
	{
		m_automatic_mode_timer->stop();
	}
	m_game_controller->reset_current_run();

	// update mission interface
	set_mission_ui_enabled(false);
	ui.missionStart->setEnabled(true);

	// re-enable programming interface
	set_programming_ui_enabled(true);

	// update the game
	ui.game->update();
}
