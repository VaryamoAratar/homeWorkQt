#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QStyle>
#include <QDebug>
#include <QTimer>

class Stopwatch: public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void StarTimer();
    void StopTimer();
    void ClearTimer();
    void NewLap();
    double GetTimeLaps();
    int GetNumLaps();

signals:

    void sig_SendTime(double time);

private slots:
    void UpdateTimes();
private:
    QTimer *timer;
    double seconds, timeLaps, timeTmp;
    int numLaps;

};

#endif // STOPWATCH_H
