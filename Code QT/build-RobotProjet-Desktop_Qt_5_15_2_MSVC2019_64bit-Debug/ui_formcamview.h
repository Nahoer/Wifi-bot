/********************************************************************************
** Form generated from reading UI file 'formcamview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCAMVIEW_H
#define UI_FORMCAMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_FormCamView
{
public:
    QWebEngineView *cam;
    QLabel *label;

    void setupUi(QWidget *FormCamView)
    {
        if (FormCamView->objectName().isEmpty())
            FormCamView->setObjectName(QString::fromUtf8("FormCamView"));
        FormCamView->resize(500, 381);
        cam = new QWebEngineView(FormCamView);
        cam->setObjectName(QString::fromUtf8("cam"));
        cam->setGeometry(QRect(-1, 39, 501, 341));
        label = new QLabel(FormCamView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 55, 16));

        retranslateUi(FormCamView);

        QMetaObject::connectSlotsByName(FormCamView);
    } // setupUi

    void retranslateUi(QWidget *FormCamView)
    {
        FormCamView->setWindowTitle(QCoreApplication::translate("FormCamView", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormCamView", "Cam\303\251ra :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCamView: public Ui_FormCamView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCAMVIEW_H
