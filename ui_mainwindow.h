/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *speed_guage;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *rpm_guage;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *car;
    QTextEdit *am;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *fuel;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *engine;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *abs;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *airbag;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *seatbelt;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *oil;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *radar_graph;
    QLCDNumber *lcdNumber;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1660, 900, 261, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1660, 960, 261, 51));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 110, 811, 741));
        speed_guage = new QHBoxLayout(horizontalLayoutWidget);
        speed_guage->setSpacing(6);
        speed_guage->setContentsMargins(11, 11, 11, 11);
        speed_guage->setObjectName(QStringLiteral("speed_guage"));
        speed_guage->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(1131, 110, 741, 741));
        rpm_guage = new QHBoxLayout(horizontalLayoutWidget_2);
        rpm_guage->setSpacing(6);
        rpm_guage->setContentsMargins(11, 11, 11, 11);
        rpm_guage->setObjectName(QStringLiteral("rpm_guage"));
        rpm_guage->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(838, 680, 261, 281));
        car = new QHBoxLayout(horizontalLayoutWidget_3);
        car->setSpacing(6);
        car->setContentsMargins(11, 11, 11, 11);
        car->setObjectName(QStringLiteral("car"));
        car->setContentsMargins(0, 0, 0, 0);
        am = new QTextEdit(centralWidget);
        am->setObjectName(QStringLiteral("am"));
        am->setGeometry(QRect(851, 570, 221, 75));
        horizontalLayoutWidget_5 = new QWidget(centralWidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(721, 960, 51, 51));
        fuel = new QHBoxLayout(horizontalLayoutWidget_5);
        fuel->setSpacing(6);
        fuel->setContentsMargins(11, 11, 11, 11);
        fuel->setObjectName(QStringLiteral("fuel"));
        fuel->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_6 = new QWidget(centralWidget);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(781, 960, 51, 51));
        engine = new QHBoxLayout(horizontalLayoutWidget_6);
        engine->setSpacing(6);
        engine->setContentsMargins(11, 11, 11, 11);
        engine->setObjectName(QStringLiteral("engine"));
        engine->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_7 = new QWidget(centralWidget);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(661, 960, 51, 51));
        abs = new QHBoxLayout(horizontalLayoutWidget_7);
        abs->setSpacing(6);
        abs->setContentsMargins(11, 11, 11, 11);
        abs->setObjectName(QStringLiteral("abs"));
        abs->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_8 = new QWidget(centralWidget);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(1104, 959, 51, 51));
        airbag = new QHBoxLayout(horizontalLayoutWidget_8);
        airbag->setSpacing(6);
        airbag->setContentsMargins(11, 11, 11, 11);
        airbag->setObjectName(QStringLiteral("airbag"));
        airbag->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_9 = new QWidget(centralWidget);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(1161, 959, 51, 51));
        seatbelt = new QHBoxLayout(horizontalLayoutWidget_9);
        seatbelt->setSpacing(6);
        seatbelt->setContentsMargins(11, 11, 11, 11);
        seatbelt->setObjectName(QStringLiteral("seatbelt"));
        seatbelt->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_10 = new QWidget(centralWidget);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(1221, 959, 51, 51));
        oil = new QHBoxLayout(horizontalLayoutWidget_10);
        oil->setSpacing(6);
        oil->setContentsMargins(11, 11, 11, 11);
        oil->setObjectName(QStringLiteral("oil"));
        oil->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_11 = new QWidget(centralWidget);
        horizontalLayoutWidget_11->setObjectName(QStringLiteral("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(841, 268, 281, 241));
        radar_graph = new QHBoxLayout(horizontalLayoutWidget_11);
        radar_graph->setSpacing(6);
        radar_graph->setContentsMargins(11, 11, 11, 11);
        radar_graph->setObjectName(QStringLiteral("radar_graph"));
        radar_graph->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(921, 515, 81, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "CRASH LINUX", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "AUTO DRIVE", 0));
        am->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:36pt; font-weight:600; color:#ffffff;\">AUTO</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
