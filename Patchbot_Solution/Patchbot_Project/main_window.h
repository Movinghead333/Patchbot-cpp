#ifndef __MAIN_WINDOW_H_DEFINED__
#define __MAIN_WINDOW_H_DEFINED__



#include "ui_main_window.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

// define UI behaviour methods
private slots:
	// programm input slots
	void on_directionUp_clicked();
	void on_directionRight_clicked();
	void on_directionDown_clicked();
	void on_directionLeft_clicked();
	void on_removeCommand_clicked();
	void on_playerWait_clicked();

	// mission control slots
	void on_missionStart_clicked();
	void on_missionCancel_clicked();
	void on_missionStep_clicked();
	void on_missionAutomatic_clicked();
	void on_missionPause_clicked();

	// change Colony slot
	void on_changeColony_clicked();

public :
	// constructor and destructor for MainWindow
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();


private:
	// gui instance
	Ui::main_window ui;

	// creates a short info-dialog with a given message and "Button clicked"
	// as title. only for debugging purposes
	void display_info_message_dialog(const std::string& p_message);
};

#endif