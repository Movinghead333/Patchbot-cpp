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
	
}

// destructor
MainWindow::~MainWindow()
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
	//display_info_message_dialog("Change Colony button clicked!");
	QString file_name = QFileDialog::getOpenFileName(this, "Open new Colony",
		"C://");
	display_info_message_dialog(file_name.toStdString());
	std::shared_ptr<Colony> new_colony =
		std::make_shared<Colony>(
			*Colony::load_colony(file_name.toStdString())
		);
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