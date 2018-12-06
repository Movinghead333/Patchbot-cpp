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
	m_game_controller = std::make_shared<GameController>(GameController());


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


// shows short information dialog displaying that a button has been clicked
// and message which button has been pressed (p_message)
void MainWindow::display_info_message_dialog(const std::string& p_message)
{
	QMessageBox::information(
		this,
		"Button clicked",
		p_message.c_str());
}