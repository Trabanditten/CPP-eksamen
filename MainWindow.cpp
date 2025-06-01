#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Vector2D.h"
#include "Velocity.h"

#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValidator>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::info(double& height, double& increment, double& angle) {
    QString heightStr = ui->Start_Height_le->text();
    height = heightStr.toDouble();
    QString incrementStr = ui->Increment_le->text();
    increment = incrementStr.toDouble();
    QString angleStr = ui->Angle_le->text();
    angle = angleStr.toDouble();
}

void MainWindow::on_pushButton_clicked()
{
    double height, angle;
    info(height, increment, angle);
    data = velocity(height, increment, angle); // Kald velocity, som nu returnerer ArrayList

    QLineSeries* series = new QLineSeries;
    for (int i = 0; i < data.size(); ++i) {
        series->append(std::get<0>(data[i]).getx(), std::get<0>(data[i]).gety());
    }

    QChart* chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("SomeData");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString speedStr = ui->Speed_le->text();
    double time = speedStr.toDouble();
    for (int i = 0; i < data.size(); ++i) {
        if (std::abs(std::get<2>(data[i]) - time) < increment/10) {
            std::string vx = std::to_string(std::get<1>(data[i]).getx());
            std::string vy = std::to_string(std::get<1>(data[i]).gety());
            std::string datatime = std::to_string(std::get<2>(data[i]));
            std::string message = "Speed at time: " + datatime + " = V_x: " + vx + ", V_y: " + vy;
            ui->statusbar->showMessage(QString::fromStdString(message));
            return;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString lengthStr = ui->Length_le->text();
    double length = lengthStr.toDouble();
    for (int i = 0; i < data.size(); ++i) {
        if (std::get<0>(data[i]).getx() > length) {
            std::string vx = std::to_string(std::get<1>(data[i]).getx());
            std::string vy = std::to_string(std::get<1>(data[i]).gety());
            std::string x = std::to_string(std::get<0>(data[i]).getx());
            std::string message = "Speed at length: " + x + " = V_x: " + vx + ", V_y: " + vy;
            ui->statusbar->showMessage(QString::fromStdString(message));
            return;
        }
    }
}
