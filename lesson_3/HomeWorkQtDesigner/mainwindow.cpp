#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialConBD = new DialogConnectBD;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialConBD;
}

void MainWindow::on_act_connectDataBase_changed()
{
    dialConBD->exec();
}


void MainWindow::on_pB_connectedToDataBase_clicked()
{
    dialConBD->exec();
}

