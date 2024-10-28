#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStyle>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new Stopwatch(this);
    connect (timer, &Stopwatch::sig_SendTime, this, &MainWindow::UpdateTimer);
    connect (timer, &Stopwatch::sig_SendLaps, this, &MainWindow::UpdateLaps);

    this->setWindowTitle("Секундомер");
    this->setStyleSheet("QMainWindow{background-color:black; }");

    ui->pB_Lap->setEnabled(false);

    ui->lb_Timer->setStyleSheet("QLabel{color:lightgreen};");
    ui->lb_Second->setStyleSheet("QLabel{color:lightgreen};");
    ui->tB_TimeLap->setStyleSheet("QTextBrowser{background-color:lightgrey; color:black; border: 2px solid grey; border-radius: 8px; }");

    ui->pB_StartStop->setText("Старт");
    ui->pB_StartStop->setStyleSheet("QPushButton{background-color:lightgrey; border: 2px solid grey; border-radius: 8px; }");

    ui->pB_Lap->setStyleSheet("QPushButton{background-color:lightgrey; border: 2px solid grey; border-radius: 8px; }");

    ui->pB_Clear->setStyleSheet("QPushButton{background-color:lightgrey; border: 2px solid grey; border-radius: 8px; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTimer(double time)
{
    ui->lb_Timer->setText(QString::number(time, 'f', 1));
}

void MainWindow::UpdateLaps(int laps, double time)
{
    ui->tB_TimeLap->append(QString("Круг: %1, время круга: %2 сек").arg(laps).arg(time));

}


void MainWindow::on_pB_StartStop_clicked()
{
    if (ui->pB_StartStop->text() == "Старт"){
        timer->StarTimer();
        ui->pB_StartStop->setText("Стоп");
        ui->pB_StartStop->setStyleSheet("QPushButton{background-color: red; border: 2px solid grey; border-radius: 8px; }");
        ui->pB_Lap->setEnabled(true);
    } else {
        timer->StopTimer();
        ui->pB_StartStop->setText("Старт");
        ui->pB_StartStop->setStyleSheet("QPushButton{background-color: lightgreen; border: 2px solid grey; border-radius: 8px; }");
        ui->pB_Lap->setEnabled(false);

    }

}


void MainWindow::on_pB_Clear_clicked()
{
    timer->ClearTimer();
    ui->tB_TimeLap->clear();

}


void MainWindow::on_pB_Lap_clicked()
{
    timer->NewLap();
}




void MainWindow::on_pB_Lap_pressed()
{
    ui->pB_Lap->setStyleSheet("QPushButton{background-color: grey; border: 2px solid grey; border-radius: 8px; }");

}


void MainWindow::on_pB_Lap_released()
{
    ui->pB_Lap->setStyleSheet("QPushButton{background-color: lightgrey; border: 2px solid grey; border-radius: 8px; }");

}


void MainWindow::on_pB_Clear_pressed()
{
    ui->pB_Clear->setStyleSheet("QPushButton{background-color: grey; border: 2px solid grey; border-radius: 8px; }");

}


void MainWindow::on_pB_Clear_released()
{
    ui->pB_Clear->setStyleSheet("QPushButton{background-color: lightgrey; border: 2px solid grey; border-radius: 8px; }");

}

