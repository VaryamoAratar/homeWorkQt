#ifndef QTTIMER_H
#define QTTIMER_H

#include <QObject>
#include <QDebug>
class QtTimer : public QObject
{
    Q_OBJECT
public:
    explicit QtTimer(QObject *parent = nullptr);
    ~QtTimer();
signals:

};

#endif // QTTIMER_H
