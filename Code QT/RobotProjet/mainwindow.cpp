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
   ui->pushButtonDeconnect->setDisabled(false);
}

void MainWindow::getInfoDialogConnexion(QString ipBot,int portBot,QString ipCam,int portCam ){


}

void MainWindow::on_pushButton_2_pressed()
{
    robotWifi->sendRouler(this->ui->spinBoxVitesseRobot->value());
}

void MainWindow::on_pushButtonDeconnect_pressed()
{
    robotWifi->disConnect();
    ui->pushButton->setDisabled(false);
    ui->pushButtonDeconnect->setDisabled(true);
}

void MainWindow::on_pushButtonStopRobot_pressed()
{
    robotWifi->sendStop();
}

void MainWindow::on_pushButtonReculer_pressed()
{
    robotWifi->sendReculer(this->ui->spinBoxVitesseRobot->value());
}

void MainWindow::on_pushButtonGauche_pressed()
{
    robotWifi->sendGauche(this->ui->spinBoxVitesseRobot->value());
}

void MainWindow::on_pushButtonDroite_pressed()
{
    robotWifi->sendDroite(this->ui->spinBoxVitesseRobot->value());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   if(event->text()=="z")
   {
       robotWifi->sendRouler(this->ui->spinBoxVitesseRobot->value());
   }
   else if(event->text()=="s")
   {
       robotWifi->sendReculer(this->ui->spinBoxVitesseRobot->value());
   }
   else if(event->text()=="q")
   {
       robotWifi->sendGauche(this->ui->spinBoxVitesseRobot->value());
   }
   else if(event->text()=="d")
   {
       robotWifi->sendDroite(this->ui->spinBoxVitesseRobot->value());
   }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
   qDebug()<<event->text();
   if(event->text()=="z")
   {
       robotWifi->sendStop();
   }
   else if(event->text()=="s")
   {
       robotWifi->sendStop();
   }
   else if(event->text()=="q")
   {
       robotWifi->sendStop();
   }
   else if(event->text()=="d")
   {
       robotWifi->sendStop();
   }
}
