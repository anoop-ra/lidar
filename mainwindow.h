#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcgaugewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QcGaugeWidget * mSpeedGauge;
    QcNeedleItem *mSpeedNeedle;
    
	QcGaugeWidget *mRPMGauge;
    QcNeedleItem *mRPMNeedle;
	
	QcGaugeWidget *mRadarArc;

};

#endif // MAINWINDOW_H
