#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) :QObject{parent}, seconds{0}, numLaps{0}, timeLaps{0}
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::UpdateTimes);

}

Stopwatch::~Stopwatch()
{
    qDebug() << "destructor called";
}

void Stopwatch::StarTimer()
{
    timer->start(100);
}

void Stopwatch::StopTimer()
{
    timer->stop();
}

void Stopwatch::ClearTimer()
{
    seconds = 0.0;
    numLaps = 0;
    timeLaps = 0.0;
    emit sig_SendTime(seconds);
    emit sig_SendLaps(numLaps, timeLaps);
}

void Stopwatch::NewLap()
{
    numLaps++;

    emit sig_SendLaps(numLaps, ((seconds - timeLaps) / 10.0));
    timeLaps = seconds;

}

void Stopwatch::UpdateTimes()
{
    seconds++;
    emit sig_SendTime(seconds / 10.0);
}
