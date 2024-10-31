#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStyle>
#include <QFont>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new Stopwatch(this);
    connect (timer, &Stopwatch::sig_SendTime, this, &MainWindow::UpdateTimer);
    // connect (timer, &Stopwatch::sig_SendLaps, this, &MainWindow::UpdateLaps);

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

    QFont fontNumbers = QFont ("Open 24 Display St", 48);
    QFont fontText = QFont ("Izuver", 20);
    QFont fontOut = QFont ("Izuver", 10);

    ui->lb_Second->setFont(fontText);
    ui->lb_Timer->setFont(fontNumbers);
    ui->pB_StartStop->setFont(fontText);
    ui->pB_Clear->setFont(fontText);
    ui->pB_Lap->setFont(fontText);
    ui->tB_TimeLap->setFont(fontOut);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTimer(double time)
{
    ui->lb_Timer->setText(QString::number(time, 'f', 1));
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
    double time = timer->GetTimeLaps() / 10;
    ui->tB_TimeLap->append(QString("Круг: %1, время круга: %2 сек").arg(timer->GetNumLaps()).arg(time));

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

