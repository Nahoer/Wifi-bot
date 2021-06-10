/********************************************************************************
** Form generated from reading UI file 'dialogconnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogConnexion
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditIpCamera;
    QLabel *label_4;
    QLineEdit *lineEditPortCamera;
    QLabel *label;
    QLineEdit *lineEditIpRobot;
    QLineEdit *lineEditPortRobot;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QString::fromUtf8("DialogConnexion"));
        DialogConnexion->resize(226, 300);
        gridLayout = new QGridLayout(DialogConnexion);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(DialogConnexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditIpCamera = new QLineEdit(DialogConnexion);
        lineEditIpCamera->setObjectName(QString::fromUtf8("lineEditIpCamera"));

        gridLayout->addWidget(lineEditIpCamera, 4, 1, 1, 1);

        label_4 = new QLabel(DialogConnexion);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEditPortCamera = new QLineEdit(DialogConnexion);
        lineEditPortCamera->setObjectName(QString::fromUtf8("lineEditPortCamera"));

        gridLayout->addWidget(lineEditPortCamera, 5, 1, 1, 1);

        label = new QLabel(DialogConnexion);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIpRobot = new QLineEdit(DialogConnexion);
        lineEditIpRobot->setObjectName(QString::fromUtf8("lineEditIpRobot"));

        gridLayout->addWidget(lineEditIpRobot, 1, 1, 1, 1);

        lineEditPortRobot = new QLineEdit(DialogConnexion);
        lineEditPortRobot->setObjectName(QString::fromUtf8("lineEditPortRobot"));

        gridLayout->addWidget(lineEditPortRobot, 2, 1, 1, 1);

        label_5 = new QLabel(DialogConnexion);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(DialogConnexion);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(DialogConnexion);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogConnexion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 2);


        retranslateUi(DialogConnexion);
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConnexion, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConnexion, SLOT(acceptInfoRobot()));

        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QCoreApplication::translate("DialogConnexion", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("DialogConnexion", "IP :", nullptr));
        label_4->setText(QCoreApplication::translate("DialogConnexion", "Camera : ", nullptr));
        label->setText(QCoreApplication::translate("DialogConnexion", "Robot :", nullptr));
        label_5->setText(QCoreApplication::translate("DialogConnexion", "IP : ", nullptr));
        label_3->setText(QCoreApplication::translate("DialogConnexion", "Port : ", nullptr));
        label_6->setText(QCoreApplication::translate("DialogConnexion", "Port : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
