#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <Qtimer>

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
    void on_cB_listProgressBar_currentIndexChanged(int index);

    void on_pB_run_clicked();


private:
    Ui::MainWindow *ui;
    int progressGreen = 0;
    int progressBlue = 0;
    int numGreenPB = 0;
    int numBluePB = 0;

};
#endif // MAINWINDOW_H
