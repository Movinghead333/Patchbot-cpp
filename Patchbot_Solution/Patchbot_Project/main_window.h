#ifndef __MAIN_WINDOW_H_DEFINED__
#define __MAIN_WINDOW_H_DEFINED__



#include "ui_main_window.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::main_window ui;
};

#endif