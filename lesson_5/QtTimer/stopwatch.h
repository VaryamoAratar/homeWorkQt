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

signals:

    void sig_SendTime(double time);
    void sig_SendLaps(int laps, double time);

private slots:
    void UpdateTimes();

private:
    QTimer *timer;
    double seconds;
    double timeLaps;
    int numLaps;

};

#endif // STOPWATCH_H
