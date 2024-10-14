#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogconnectbd.h"

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

private slots:
    void on_act_connectDataBase_changed();


    void on_pB_connectedToDataBase_clicked();

private:
    Ui::MainWindow *ui;
    DialogConnectBD *dialConBD;
};
#endif // MAINWINDOW_H
