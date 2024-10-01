#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphicWindow(QWidget *parent = nullptr);
    ~GraphicWindow();


    void ClearGraph();
    void UpdateGraphic(QMap<double, double> mapData);

signals:
    void readyToShow();

private:
    Ui::GraphicWindow *ui;
    QChart* chart;
    QChartView* chartView;
    QLineSeries* mainLineSeries;
};

#endif // GRAPHICWINDOW_H
