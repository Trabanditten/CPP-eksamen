#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QValidator>
#include "Vector2D.h"
#include "ArrayList.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void info(double& height, double& increment, double& angle);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    ArrayList<std::tuple<Vector2D, Vector2D, double>> data; // Ændret til ArrayList
    Ui::MainWindow *ui;
    double increment;
};
#endif // MAINWINDOW_H
