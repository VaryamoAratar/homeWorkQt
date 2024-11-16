#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>

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
    void ScreenDataFromDB(const QAbstractTableModel *model, int typeTb);
private slots:
    void ReceiveStatusConnectionToDB(bool status);

    void on_pB_Get_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DataBase *dataBase;
    QMessageBox* msg;
    QVector<QString> data;
};
#endif // MAINWINDOW_H
