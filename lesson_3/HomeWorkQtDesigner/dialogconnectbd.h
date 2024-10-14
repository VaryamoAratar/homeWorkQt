#ifndef DIALOGCONNECTBD_H
#define DIALOGCONNECTBD_H

#include <QDialog>

namespace Ui {
class DialogConnectBD;
}

class DialogConnectBD : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnectBD(QWidget *parent = nullptr);
    ~DialogConnectBD();

private:
    Ui::DialogConnectBD *ui;
};

#endif // DIALOGCONNECTBD_H
