/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Start_Height_lbl;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *Start_Height_le;
    QLabel *Angle_lbl;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Angle_le;
    QLabel *Increment_lbl;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *Increment_le;
    QLabel *Speed_lbl;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *Speed_le;
    QLabel *Length_lbl;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *Length_le;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        Start_Height_lbl = new QLabel(centralwidget);
        Start_Height_lbl->setObjectName("Start_Height_lbl");

        formLayout->setWidget(0, QFormLayout::LabelRole, Start_Height_lbl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        Start_Height_le = new QLineEdit(centralwidget);
        Start_Height_le->setObjectName("Start_Height_le");

        verticalLayout_9->addWidget(Start_Height_le);


        horizontalLayout->addLayout(verticalLayout_9);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        Angle_lbl = new QLabel(centralwidget);
        Angle_lbl->setObjectName("Angle_lbl");

        formLayout->setWidget(1, QFormLayout::LabelRole, Angle_lbl);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        Angle_le = new QLineEdit(centralwidget);
        Angle_le->setObjectName("Angle_le");

        verticalLayout_2->addWidget(Angle_le);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout_2);

        Increment_lbl = new QLabel(centralwidget);
        Increment_lbl->setObjectName("Increment_lbl");

        formLayout->setWidget(2, QFormLayout::LabelRole, Increment_lbl);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        Increment_le = new QLineEdit(centralwidget);
        Increment_le->setObjectName("Increment_le");

        verticalLayout_10->addWidget(Increment_le);


        formLayout->setLayout(2, QFormLayout::FieldRole, verticalLayout_10);

        Speed_lbl = new QLabel(centralwidget);
        Speed_lbl->setObjectName("Speed_lbl");

        formLayout->setWidget(3, QFormLayout::LabelRole, Speed_lbl);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        Speed_le = new QLineEdit(centralwidget);
        Speed_le->setObjectName("Speed_le");

        verticalLayout_7->addWidget(Speed_le);


        horizontalLayout_7->addLayout(verticalLayout_7);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_7);

        Length_lbl = new QLabel(centralwidget);
        Length_lbl->setObjectName("Length_lbl");

        formLayout->setWidget(4, QFormLayout::LabelRole, Length_lbl);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        Length_le = new QLineEdit(centralwidget);
        Length_le->setObjectName("Length_le");

        verticalLayout_8->addWidget(Length_le);


        formLayout->setLayout(4, QFormLayout::FieldRole, verticalLayout_8);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Stj\303\246ler Oplysninger", nullptr));
        Start_Height_lbl->setText(QCoreApplication::translate("MainWindow", "Start Height", nullptr));
        Angle_lbl->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        Increment_lbl->setText(QCoreApplication::translate("MainWindow", "Increment", nullptr));
        Speed_lbl->setText(QCoreApplication::translate("MainWindow", "Speed at time (Optional)", nullptr));
        Length_lbl->setText(QCoreApplication::translate("MainWindow", "Speed at length (Optional)", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Speed at time", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Speed at length", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
