#ifndef __MAIN_WINDOW_H_DEFINED__
#define __MAIN_WINDOW_H_DEFINED__

#include "ui_main_window.h"
#include "gamecontroller.h"


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

	// dropdown update slot
	void repititions_changed(const QString& p_new_text);

	// scrollbar slots
	void scroll_x(int p_new_value);
	void scroll_y(int p_new_value);
	void scroll_program(int p_new_value);

public:
	// constructor and destructor for MainWindow
	MainWindow(QWidget *parent = Q_NULLPTR);

protected:
	// gets called whenever a window property changes
	void paintEvent(QPaintEvent *event);

	// gets called whenever the size of the window changes
	void resizeEvent(QResizeEvent *event);


private:
	// TODO maybe combine the following two methods
	// enables or disables the programming ui
	void set_programming_ui_enabled(bool enabled);

	// enables or disables the mission interface
	void set_mission_ui_enabled(bool enabled);

	// gui instance
	Ui::main_window ui;

	// game controller
	std::shared_ptr<GameController> m_game_controller;


	// creates a short info-dialog with a given message and "Button clicked"
	// as title. only for debugging purposes
	void display_info_message_dialog(const std::string& title,
									 const std::string& p_message);

	// display an error-dialog with a given title as well as a given message
	void display_error_message_dialog(const std::string& p_title,
									  const std::string& p_message);

	// calculates render offsets based on window size and scrollbar-position
	void calculate_render_details();

	// update the program scrollbar
	void update_program_scroll_max();

	// check if the game is won or lost
	void check_win_and_loose_conditions();
};

#endif