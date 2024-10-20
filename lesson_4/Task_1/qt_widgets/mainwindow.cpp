#include "mainwindow.h"
#include "./ui_mainwindow.h"

enum class color_progress_bar{
    GREEN,
    BLUE
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rB_inr->setText("Инкремент");
    ui->rB_inr->setChecked(true);

    ui->rB_decr->setText("Декремент");

    ui->cB_listProgressBar->addItem("Зеленый прогресс-бар");
    ui->cB_listProgressBar->addItem("Синий прогресс бар");

    ui->pB_run->setText("Применить");
    ui->pB_run->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_cB_listProgressBar_currentIndexChanged(int index)
{

    if(index == static_cast<int>(color_progress_bar::GREEN)){
        ui->sB_runNum->setValue(numGreenPB);
        ui->pBar_result->setStyleSheet("QProgressBar::chunk{ background-color: lightgreen;}"
                                       "QProgressBar{ border: 2px solid grey; border-radius: 5px; text-align: center;}");
        ui->pBar_result->setValue(progressGreen);
    };
    if(index == static_cast<int>(color_progress_bar::BLUE)){
        ui->sB_runNum->setValue(numBluePB);
        ui->pBar_result->setStyleSheet("QProgressBar::chunk{ background-color: blue;}"
                                       "QProgressBar{ border: 2px solid grey; border-radius: 5px; text-align: center;}");
        ui->pBar_result->setValue(progressBlue);

    };

}


void MainWindow::on_pB_run_clicked()
{
    if(ui->rB_inr->isChecked()){
        if(ui->cB_listProgressBar->currentIndex() == static_cast<int>(color_progress_bar::GREEN)){
            ++progressGreen;
            ui->pBar_result->setValue(progressGreen);
            if (progressGreen > 10){
                progressGreen = 0;
                numGreenPB++;
                ui->sB_runNum->setValue(numGreenPB);
                ui->pBar_result->setValue(progressGreen);
            }


        }
        if(ui->cB_listProgressBar->currentIndex() == static_cast<int>(color_progress_bar::BLUE)){
            ++progressBlue;
            ui->pBar_result->setValue(progressBlue);
                if (progressBlue > 10){
                    progressBlue = 0;
                    numBluePB++;
                    ui->sB_runNum->setValue(numBluePB);

                    ui->pBar_result->setValue(progressBlue);
                }
            }

    };
    if(ui->rB_decr->isChecked()){
        if(ui->cB_listProgressBar->currentIndex() == static_cast<int>(color_progress_bar::GREEN)){
            --progressGreen;
                if (progressGreen <= 0){
                    progressGreen = 0;
                }
            ui->pBar_result->setValue(progressGreen);

        }
        if(ui->cB_listProgressBar->currentIndex() == static_cast<int>(color_progress_bar::BLUE)){
            --progressBlue;
                if (progressBlue <= 0){
                    progressBlue = 0;
                }
            ui->pBar_result->setValue(progressBlue);
        }
    }
}



