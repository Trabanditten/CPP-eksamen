#include "MainWindow.h"
#include "Velocity.h"
#include "Vector2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w; // Sender VectorListe til MainWindow.cpp
    w.show();
    return a.exec();
}
