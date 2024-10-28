#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void UpdateTimer(double time);
    void UpdateLaps(int laps, double time);
private slots:



    void on_pB_StartStop_clicked();

    void on_pB_Clear_clicked();

    void on_pB_Lap_clicked();

    void on_pB_Lap_pressed();

    void on_pB_Lap_released();

    void on_pB_Clear_pressed();

    void on_pB_Clear_released();

private:
    Ui::MainWindow *ui;
    Stopwatch *timer;
};
#endif // MAINWINDOW_H
