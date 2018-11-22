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

/*

void MainWindow::on_testBtn_clicked()
{
	ui.label_test->setText("button clicked");
}

*/
