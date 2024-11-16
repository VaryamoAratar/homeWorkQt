#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
    data[hostName] = "localhost";
    data[dbName] = "study";
    data[login] = "postgres";
    data[pass] = "mellon";
    data[port] = "5432";


    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    auto conn = [&](){dataBase->ConnectToDataBase(data);};
    QtConcurrent::run(conn);

    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendDataFromDB, this, &MainWindow::ScreenDataFromDB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->lb_Status->setText("Подключено к БД");
        ui->lb_Status->setStyleSheet("color:green");
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_Status->setText("Отключено");
        ui->lb_Status->setStyleSheet("color:red");
        msg->exec();
    }

}

void MainWindow::on_pB_Get_clicked()
{
    ui->tbV_tableResult->setModel(0);

    if (ui->cB_Request->currentIndex() == requestAllFilms - 1)
    {
        dataBase->RequestToDB("");
    }
    else
    {
        dataBase->RequestToDB("select musician_id from musician");
    }
}

void MainWindow::ScreenDataFromDB(const QAbstractTableModel *model, int typeTb)
{
    if (typeTb == requestAllFilms)
    {
        ui->tbV_tableResult->setModel(const_cast<QAbstractTableModel*>(model));
        // qDebug() << model->columnCount();
        ui->tbV_tableResult->hideColumn(0);
        // for (int i = 0; i < model->columnCount(); i++)
        // {
        //     if (i != 1 || i != 2)
        //     {
        //         ui->tbV_tableResult->hideColumn(i);
        //     }
        // }
        // ui->tbV_tableResult->update();
    }
    else
    {
        ui->tbV_tableResult->setModel(const_cast<QAbstractTableModel*>(model));
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tbV_tableResult->setModel(0);
}

