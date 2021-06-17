#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myrobot.h>
#include "dialogconnexion.h"
#include <QString>
#include <QKeyEvent>
#include <QVector>
#include "formcamview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectToRobot();
    void disconnectToRobot();
private slots:
    void openDialogConnexion();
    void getInfoDialogConnexion();

    void on_pushButton_2_pressed();
    void on_pushButtonStopRobot_pressed();
    void on_pushButtonReculer_pressed();
    void on_pushButtonGauche_pressed();
    void on_pushButtonDroite_pressed();

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    void refreshInfos();
    void on_verticalSlider_valueChanged(int value);

    void on_actionReconnexion_triggered();

private:
    Ui::MainWindow *ui;
    MyRobot *robotWifi;
    QTimer *timerRefresh;
    DialogConnexion *dialogConnect;
    int vitesse;
    QVector<QString> infosLogin;
};
#endif // MAINWINDOW_H
