#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLCDNumber>
#include <QLabel>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "chartview.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPolarChart>
#include <QtCore/QDebug>
#include <pthread.h>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <unistd.h>
#include <algorithm>
#include <iterator>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

#define PORT 8080

pthread_t th;


static int speed = 40;
static int rpm   = 0;
static int a = 1;
static int running = 1;
pthread_t threadId;

#if 0
#pragma qt_class(QtMath)
#endif

typedef struct
{
	Ui::MainWindow *ui;
	QcNeedleItem *mSpeedNeedle;
	QcNeedleItem *mRPMNeedle;
}DATA;

int angle[360],dist[360];
int a2=0,j=0;

typedef struct
{
    QSplineSeries *series2;
    QPolarChart *chart;
    ChartView *chartView;
    QValueAxis *angularAxis;
    QValueAxis *radialAxis;
    QSerialPort *serial;
    QByteArray *datas;
    //    int angle[360],dist[360];


} GRAPH_DATA;

void *Line(void * data)
{
    GRAPH_DATA* gData = (GRAPH_DATA*) data;

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1500] = {0};
    //char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        //printf("Going to read\n");
        qDebug() << "Going to read";
        memset(dist, 0x0, 360);
        memset(&buffer, 0x0, 1500);
        valread = read( new_socket , &buffer, 1500);
        //printf("Number of bytes read = %d", valread);
        qDebug() << "The value is" << valread;
        //Fstring(buffer);
        for (int i = 4; i < valread;i=i+16)
        {   dist[a2]=(buffer[i+8]);
//            int ang = 0;
//            int dst = 0;
            //printf("%c", buffer[i]);
//            dist[a] =static_cast<int>(buffer[i]);
//            a++;
            //std::cout << buffer[i++];
//            ang = buffer[i++];
//            ang = ang << 8;
//            ang = ang & buffer[i++];
//            qDebug() << ang;
//            dst = buffer[i++];
//            qDebug() << dst;
//            i++;
            //static_cast<int>
            //qDebug() << buffer[i];
            //qDebug() << angle[i];
            //qDebug() << dist[i];
//            gData->series2->append(j, a);
            a2++;
            qDebug() << dist[a2];
        }

        sleep(1);
        //a=0;
        for(int j=0;j<360;j++)
            gData->series2->append(j, dist[j]);
        usleep(1000 * 1000);
        //sleep(1);
        gData->series2->clear();
    }

}
	
void * threadFunc(void * arg)
{
	DATA* s_data = (DATA*) arg;

    // Sleep for 2 seconds
    while(running)
    {
#if 1
        if(a == 1)
        {   
			++rpm;
        }
        else
        {
			--rpm;
        }
#endif

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		char time[16] = {'\0'};
		sprintf(time, "%d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);	
    	s_data->ui->lcdNumber->display(time);
		speed = rand() % (65 + 1 - 60) + 60;
		s_data->mSpeedNeedle->setCurrentValue(speed);	
		s_data->mRPMNeedle->setCurrentValue(rpm);	
    
        if(rpm == 8)
            a = 0; 
        else if (rpm == 0)
            a = 1;

        usleep(100000);
    }
    return NULL;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

	DATA*  s_data = new DATA;

    ui->setupUi(this);

    GRAPH_DATA* gData = (GRAPH_DATA*) malloc(sizeof(GRAPH_DATA));

    const qreal radialMin = 0;
    const qreal radialMax = 70;
    gData->serial=new QSerialPort;
    QPen p;
    p.setWidth(3);
    gData->series2 = new QSplineSeries();
    gData->series2->setName("spline");
    gData->series2->setPen(p);

    pthread_create(&th, NULL, &Line, gData);

    gData->chart = new QPolarChart();
    gData->chart->setBackgroundVisible(false);

    gData->chart->addSeries(gData->series2);

    gData->angularAxis = new QValueAxis();
    gData->angularAxis->setTickCount(9); //First and last ticks are co-located on 0/360 angle.
    gData->angularAxis->setLabelFormat("0");
    gData->angularAxis->setShadesVisible(false);
    gData->angularAxis->setShadesBrush(QBrush(QColor(0, 255, 0)));
    gData->chart->addAxis(gData->angularAxis, QPolarChart::PolarOrientationAngular);
    gData->chart->legend()->hide();

    gData->radialAxis = new QValueAxis();
    gData->radialAxis->setTickCount(9);
    gData->radialAxis->setLabelFormat("0");
    gData->chart->addAxis(gData->radialAxis, QPolarChart::PolarOrientationRadial);

    gData->series2->attachAxis(gData->radialAxis);
    gData->series2->attachAxis(gData->angularAxis);

    gData->series2->setColor(QColor(255,0,0));

    gData->radialAxis->setRange(radialMin, radialMax);

    gData->angularAxis->setRange(0, 360);

    gData->chartView = new ChartView();
    gData->chartView->setChart(gData->chart);
    gData->chartView->setRenderHint(QPainter::Antialiasing);


	// To show full screen
    //QMainWindow::showFullScreen();
    this->setStyleSheet("background-color: black;");

    ui->lcdNumber->setDigitCount(8);

    mSpeedGauge = new QcGaugeWidget;
    mSpeedGauge->addBackground(92);
    QcBackgroundItem *bkg1 = mSpeedGauge->addBackground(90);
    bkg1->clearrColors();
    bkg1->addColor(1.0,Qt::red);
    bkg1->addColor(0.7,Qt::black);

    QcBackgroundItem *bkg2 = mSpeedGauge->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::black);
    bkg2->addColor(1.0,Qt::black);

    mSpeedGauge->addArc(55);
    mSpeedGauge->addDegrees(90)->setValueRange(0,160);
    mSpeedGauge->addColorBand(50);

    mSpeedGauge->addValues(70)->setValueRange(0,160);

    mSpeedGauge->addLabel(70)->setText("kmph");
    QcLabelItem *lab = mSpeedGauge->addLabel(40);
    lab->setText("0");
    mSpeedNeedle = mSpeedGauge->addNeedle(75);
    mSpeedNeedle->setLabel(lab);
    mSpeedNeedle->setColor(Qt::white);
    mSpeedNeedle->setValueRange(0,160);
    mSpeedGauge->addBackground(7);
    mSpeedGauge->addGlass(88);
    ui->speed_guage->addWidget(mSpeedGauge);


	// TODO: RPM 
    mRPMGauge = new QcGaugeWidget;
    mRPMGauge->addBackground(92);
    QcBackgroundItem *bkg4 = mRPMGauge->addBackground(90);
    bkg4->clearrColors();
    bkg4->addColor(1.0,Qt::red);
    bkg4->addColor(0.7,Qt::black);

    QcBackgroundItem *bkg3 = mRPMGauge->addBackground(88);
    bkg3->clearrColors();
    bkg3->addColor(0.1,Qt::black);
    bkg3->addColor(1.0,Qt::black);

    mRPMGauge->addArc(55);
    mRPMGauge->addDegrees(90)->setValueRange(0,20);
    mRPMGauge->addColorBand(50);

    mRPMGauge->addValues(70)->setValueRange(0,20);

    mRPMGauge->addLabel(70)->setText("rpm x1000");
    //QcLabelItem *lab1 = mRPMGauge->addLabel(40);
    //lab1->setText("0");
    mRPMNeedle = mRPMGauge->addNeedle(75);
    //mRPMNeedle->setLabel(lab1);
    mRPMNeedle->setColor(Qt::white);
    mRPMNeedle->setValueRange(0,20);
    mRPMGauge->addBackground(7);
    mRPMGauge->addGlass(88);
    ui->rpm_guage->addWidget(mRPMGauge);

	// Radar graph
	//mRadarArc = new QcGaugeWidget();
	//mRadarArc->addArc(55);
    //mRadarArc->addDegrees(30)->setValueRange(30,80);
    //mRadarArc->addColorBand(50);
	//ui->radar_graph->addWidget(mRadarArc);

	// Car
	QPixmap image("car.png");
	QLabel* imageLabel = new QLabel();
	imageLabel->setPixmap(image);
	imageLabel->setAlignment(Qt::AlignCenter);
	ui->car->addWidget(imageLabel);
	
	// Red line
	//QPixmap image1("red.png");
	//QLabel* imageLabel1 = new QLabel();
	//imageLabel1->setPixmap(image1);
	//imageLabel1->setAlignment(Qt::AlignCenter);
	//ui->red->addWidget(imageLabel1);


	// fuel line
	QPixmap image2("fuel.png");
	QLabel* imageLabel2 = new QLabel();
	imageLabel2->setPixmap(image2);
	imageLabel2->setAlignment(Qt::AlignCenter);
	ui->fuel->addWidget(imageLabel2);


	// oil line
	QPixmap image3("oil.png");
	QLabel* imageLabel3 = new QLabel();
	imageLabel3->setPixmap(image3);
	imageLabel3->setAlignment(Qt::AlignCenter);
	ui->oil->addWidget(imageLabel3);


	// abs line
	QPixmap image4("abs.png");
	QLabel* imageLabel4 = new QLabel();
	imageLabel4->setPixmap(image4);
	imageLabel4->setAlignment(Qt::AlignCenter);
	ui->abs->addWidget(imageLabel4);


	// seatbelt line
	QPixmap image5("seatbelt.png");
	QLabel* imageLabel5 = new QLabel();
	imageLabel5->setPixmap(image5);
	imageLabel5->setAlignment(Qt::AlignCenter);
	ui->seatbelt->addWidget(imageLabel5);


	// airbag line
	QPixmap image6("airbag.png");
	QLabel* imageLabel6 = new QLabel();
	imageLabel6->setPixmap(image6);
	imageLabel6->setAlignment(Qt::AlignCenter);
	ui->airbag->addWidget(imageLabel6);


	// engine line
	QPixmap image7("engine.png");
	QLabel* imageLabel7 = new QLabel();
	imageLabel7->setPixmap(image7);
	imageLabel7->setAlignment(Qt::AlignCenter);
	ui->engine->addWidget(imageLabel7);

    ui->radar_graph->addWidget(gData->chartView);


	// Auto
	ui->am->setFrameStyle(QFrame::NoFrame);
	ui->am->setTextColor( QColor(255,0,0) );
	//QTextDocument* text =  new QTextDocument("MANUAL");
	//ui->am->setDocument(text);

	// Proximity (Add color to widget)
	//QWidget *widget1 = new QWidget();
	//widget1->setStyleSheet("background-color: grey");
	//ui->prox1->addWidget(widget1);

	s_data->ui = ui;
	s_data->mSpeedNeedle = mSpeedNeedle;
	s_data->mRPMNeedle   = mRPMNeedle;

    pthread_create(&threadId, NULL, &threadFunc, s_data);
}

MainWindow::~MainWindow()
{
	running = 0;
	pthread_join(threadId, NULL);
    delete ui;
}

