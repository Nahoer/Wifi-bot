/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "formcamview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnexion;
    QWidget *centralwidget;
    QPushButton *pushButton;
    FormCamView *widgetCamStream;
    QPushButton *pushButtonDeconnect;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_BatterieValue;
    QLabel *label_Version;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButtonGauche;
    QPushButton *pushButtonStopRobot;
    QPushButton *pushButtonDroite;
    QPushButton *pushButtonReculer;
    QSplitter *splitter;
    QSlider *verticalSlider;
    QLabel *labelVitesse;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuParam_tres;
    QStatusBar *statusbarVitesse;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(876, 612);
        actionConnexion = new QAction(MainWindow);
        actionConnexion->setObjectName(QString::fromUtf8("actionConnexion"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 80, 25));
        widgetCamStream = new FormCamView(centralwidget);
        widgetCamStream->setObjectName(QString::fromUtf8("widgetCamStream"));
        widgetCamStream->setGeometry(QRect(350, 0, 500, 380));
        pushButtonDeconnect = new QPushButton(centralwidget);
        pushButtonDeconnect->setObjectName(QString::fromUtf8("pushButtonDeconnect"));
        pushButtonDeconnect->setGeometry(QRect(140, 10, 80, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 60, 61, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 60, 55, 16));
        label_BatterieValue = new QLabel(centralwidget);
        label_BatterieValue->setObjectName(QString::fromUtf8("label_BatterieValue"));
        label_BatterieValue->setGeometry(QRect(30, 80, 201, 20));
        label_BatterieValue->setTextFormat(Qt::AutoText);
        label_BatterieValue->setAlignment(Qt::AlignCenter);
        label_Version = new QLabel(centralwidget);
        label_Version->setObjectName(QString::fromUtf8("label_Version"));
        label_Version->setGeometry(QRect(230, 90, 55, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 340, 141, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButtonGauche = new QPushButton(widget);
        pushButtonGauche->setObjectName(QString::fromUtf8("pushButtonGauche"));

        gridLayout->addWidget(pushButtonGauche, 1, 0, 1, 1);

        pushButtonStopRobot = new QPushButton(widget);
        pushButtonStopRobot->setObjectName(QString::fromUtf8("pushButtonStopRobot"));

        gridLayout->addWidget(pushButtonStopRobot, 1, 1, 1, 1);

        pushButtonDroite = new QPushButton(widget);
        pushButtonDroite->setObjectName(QString::fromUtf8("pushButtonDroite"));

        gridLayout->addWidget(pushButtonDroite, 1, 2, 1, 1);

        pushButtonReculer = new QPushButton(widget);
        pushButtonReculer->setObjectName(QString::fromUtf8("pushButtonReculer"));

        gridLayout->addWidget(pushButtonReculer, 2, 1, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 340, 41, 161));
        splitter->setOrientation(Qt::Vertical);
        verticalSlider = new QSlider(splitter);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimum(90);
        verticalSlider->setMaximum(240);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Vertical);
        splitter->addWidget(verticalSlider);
        labelVitesse = new QLabel(splitter);
        labelVitesse->setObjectName(QString::fromUtf8("labelVitesse"));
        labelVitesse->setAlignment(Qt::AlignCenter);
        splitter->addWidget(labelVitesse);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        splitter->addWidget(label);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 876, 25));
        menuParam_tres = new QMenu(menubar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        MainWindow->setMenuBar(menubar);
        statusbarVitesse = new QStatusBar(MainWindow);
        statusbarVitesse->setObjectName(QString::fromUtf8("statusbarVitesse"));
        MainWindow->setStatusBar(statusbarVitesse);

        menubar->addAction(menuParam_tres->menuAction());
        menuParam_tres->addAction(actionConnexion);

        retranslateUi(MainWindow);
        QObject::connect(menubar, SIGNAL(triggered(QAction*)), MainWindow, SLOT(openDialogConnexion()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnexion->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        pushButtonDeconnect->setText(QCoreApplication::translate("MainWindow", "Deconnexion", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Batterie", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        label_BatterieValue->setText(QString());
        label_Version->setText(QString());
        pushButton_2->setText(QString());
        pushButtonGauche->setText(QString());
        pushButtonStopRobot->setText(QString());
        pushButtonDroite->setText(QString());
        pushButtonReculer->setText(QString());
        labelVitesse->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vitesse", nullptr));
        menuParam_tres->setTitle(QCoreApplication::translate("MainWindow", "Param\303\251tres", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
