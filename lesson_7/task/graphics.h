#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QObject>
#include "qcustomplot.h"

#define FIRST_GRAPH 0

class Graphics : public QObject
{
    Q_OBJECT
public:

    Graphics(QCustomPlot* cPlot, uint32_t numGraph);
    void AddDataToGrahp(QVector<double> y, uint32_t numGraph, int FD);
    void ClearGraph(QCustomPlot* cPlot);
    void UpdateGraph(QCustomPlot* cPlot);

private:
    QList<QCPGraph*> ptrGraph;

signals:
};

#endif // GRAPHICS_H
