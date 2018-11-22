#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("PATCHBOT v1.0");
}

MainWindow::~MainWindow()
{
}
