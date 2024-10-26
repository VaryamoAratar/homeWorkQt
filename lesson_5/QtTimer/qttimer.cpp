#include "qttimer.h"

QtTimer::QtTimer(QObject *parent)
    : QObject{parent}
{}

QtTimer::~QtTimer(){
    qDebug() << "QtTimer delete";
}
