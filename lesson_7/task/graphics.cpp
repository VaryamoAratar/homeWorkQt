#include "graphics.h"

// Graphics::Graphics(QObject *parent)
//     : QObject{parent}
// {}
Graphics::Graphics(QCustomPlot* cPlot, uint32_t numGraph)
{
    ptrGraph.resize(numGraph);

    for(int i = 0; i<ptrGraph.size(); i++){
        ptrGraph[i] = new QCPGraph(cPlot->xAxis, cPlot->yAxis);
    }
    cPlot->setInteraction(QCP::iRangeZoom, true);
    cPlot->setInteraction(QCP::iRangeDrag, true);
}

void Graphics::AddDataToGrahp(QVector<double> y, uint32_t numGraph, int FD)
{
    QVector<double> x;
    x.resize(FD);
    y.resize(FD);

    for(int i = 0; i < x.size(); i++){
        x[i] = i + 1;
    }

    ptrGraph[numGraph]->addData(x,y);

}

void Graphics::ClearGraph(QCustomPlot* cPlot)
{
    for(int i = 0; i<ptrGraph.size(); i++){
        ptrGraph[i]->data().clear();
    }

    for(int i = 0; i< cPlot->graphCount(); i++){
        cPlot->graph(i)->data()->clear();
    }
    cPlot->replot();

}

void Graphics::UpdateGraph(QCustomPlot *cPlot){
    cPlot->rescaleAxes();
    cPlot->replot();
}
