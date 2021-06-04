#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    robotWifi = new MyRobot(this);
    timerRefresh = new QTimer;
    connect(timerRefresh, SIGNAL(timeout()), this, SLOT(refreshInfos()));
    vitesse=90;
    this->ui->labelVitesse->setText(QString::number(vitesse));
    this->ui->pushButton_2->setIcon(QIcon("D:/Telechargement/chevron_up.svg"));
     this->ui->pushButtonReculer->setIcon(QIcon("D:/Telechargement/chevron_down.svg"));
     this->ui->pushButtonDroite->setIcon(QIcon("D:/Telechargement/chevron_right.svg"));
     this->ui->pushButtonGauche->setIcon(QIcon("D:/Telechargement/chevron_left.svg"));
    this->ui->pushButtonStopRobot->setIcon(QIcon("D:/Telechargement/square_stop.svg"));
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
   timerRefresh->start(50);
}

void MainWindow::getInfoDialogConnexion(QString ipBot,int portBot,QString ipCam,int portCam ){


}

void MainWindow::on_pushButton_2_pressed()
{
    robotWifi->sendRouler(vitesse);
}

void MainWindow::on_pushButtonDeconnect_pressed()
{
    robotWifi->disConnect();
    ui->pushButton->setDisabled(false);
    ui->pushButtonDeconnect->setDisabled(true);
    timerRefresh->stop();
}

void MainWindow::on_pushButtonStopRobot_pressed()
{
    robotWifi->sendStop();
}

void MainWindow::on_pushButtonReculer_pressed()
{
    robotWifi->sendReculer(vitesse);

}

void MainWindow::on_pushButtonGauche_pressed()
{
    robotWifi->sendGauche(vitesse);

}

void MainWindow::on_pushButtonDroite_pressed()
{
    robotWifi->sendDroite(vitesse);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
   if(event->text()=="z"||event->text()=="Z")
   {
       robotWifi->sendRouler(vitesse);
   }
   else if(event->text()=="s"||event->text()=="S")
   {
       robotWifi->sendReculer(vitesse);
   }
   else if(event->text()=="q"||event->text()=="Q")
   {
       robotWifi->sendGauche(vitesse);
   }
   else if(event->text()=="d"||event->text()=="D")
   {
       robotWifi->sendDroite(vitesse);
   }
   else if(event->text()=="zd"||event->text()=="ZD")
   {
       robotWifi->sendReculer(vitesse);
   }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
   if(event->text()=="z"||event->text()=="Z")
   {
       ui->pushButtonStopRobot->pressed();
   }
   else if(event->text()=="s"||event->text()=="S")
   {
       ui->pushButtonStopRobot->pressed();
   }
   else if(event->text()=="q"||event->text()=="Q")
   {
       ui->pushButtonStopRobot->pressed();
   }
   else if(event->text()=="d"||event->text()=="D")
   {
       ui->pushButtonStopRobot->pressed();
   }
}

void MainWindow::refreshInfos()
{

    QString batterie=robotWifi->getBatterie();
    if(batterie.toInt()<0)
    {
       ui->label_BatterieValue->setText("Connexion en cours");
       ui->label_Version->setText(robotWifi->getVersion());
    }
    else
    {
        if(batterie.toInt()>99)
           {
            ui->label_BatterieValue->setText("100%");
            ui->label_Version->setText(robotWifi->getVersion());
            }
        else
        {
            ui->label_BatterieValue->setText(robotWifi->getBatterie()+"%");
            ui->label_Version->setText(robotWifi->getVersion());
            timerRefresh->start(50);
        }

    }
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    vitesse=value;
    this->ui->labelVitesse->setText(QString::number(vitesse));
}
