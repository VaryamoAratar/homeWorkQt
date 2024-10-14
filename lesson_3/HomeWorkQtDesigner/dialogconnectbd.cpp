#include "dialogconnectbd.h"
#include "ui_dialogconnectbd.h"

DialogConnectBD::DialogConnectBD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConnectBD)
{
    ui->setupUi(this);
}

DialogConnectBD::~DialogConnectBD()
{
    delete ui;
}
