#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QtTimer(this);
    this->setWindowTitle("Секундомер");

}

MainWindow::~MainWindow()
{
    delete ui;
}
