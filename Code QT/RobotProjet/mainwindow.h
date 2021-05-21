#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myrobot.h>
#include "dialogconnexion.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();
    void openDialogConnexion();
    void getInfoDialogConnexion(QString ipBot,int portBot,QString ipCam,int portCam );
    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;
    MyRobot *robotWifi;
};
#endif // MAINWINDOW_H
