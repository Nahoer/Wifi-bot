#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    robotWifi = new MyRobot(this);
    //robotwifi.doConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialogConnexion(){
    DialogConnexion dialogConnect(this);
    dialogConnect.exec();
}

void MainWindow::on_pushButton_pressed()
{
   robotWifi->doConnect();
   ui->pushButton->setDisabled(true);
}

void MainWindow::getInfoDialogConnexion(QString ipBot,int portBot,QString ipCam,int portCam ){


}

void MainWindow::on_pushButton_2_pressed()
{
    robotWifi->sendRouler(120);
}
