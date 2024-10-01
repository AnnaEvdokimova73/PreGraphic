#include "graphicwindow.h"
#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);
    chart = new QChart();
    chart->legend()->setVisible(false);
    //Объект QChartView является виджетом отображальщиком графика.
    //В его конструктор передается ссылка на объект QChart.
    chartView = new QChartView(chart);
    mainLineSeries = new QLineSeries();
    ui->gridLayout->addWidget(chartView);
    chartView->show();
}

GraphicWindow::~GraphicWindow()
{
    delete chart;
    delete chartView;
    delete mainLineSeries;
    delete ui;
}

void GraphicWindow::ClearGraph()
{
    //Необходимо очистить график
    mainLineSeries->clear();
    //Удаляем серию из графика
    chart->removeSeries(mainLineSeries);
}

void GraphicWindow::UpdateGraphic(QMap<double, double> mapData)
{
    if(!chart->series().isEmpty())
    {
        ClearGraph();
    }

    for (auto key : mapData.keys())
    {
        mainLineSeries->append(key, mapData.value(key));
    }

    chart->addSeries(mainLineSeries);

    emit readyToShow();
}
