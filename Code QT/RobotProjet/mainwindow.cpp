#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    robotWifi = new MyRobot(this);
    dialogConnect = new DialogConnexion(this);
    timerRefresh = new QTimer;
    dialogConnect = new DialogConnexion(this);
    vitesse=90;
    this->ui->labelVitesse->setText(QString::number(vitesse));
    this->ui->pushButton_2->setIcon(QIcon("images/chevron_up.svg"));
    this->ui->pushButtonReculer->setIcon(QIcon("images/chevron_down.svg"));
    this->ui->pushButtonDroite->setIcon(QIcon("images/chevron_right.svg"));
    this->ui->pushButtonGauche->setIcon(QIcon("images/chevron_left.svg"));
    this->ui->pushButtonStopRobot->setIcon(QIcon("images/square_stop.svg"));
    connect(timerRefresh, SIGNAL(timeout()), this, SLOT(refreshInfos()));
    connect(dialogConnect, SIGNAL(accepted()),this, SLOT(getInfoDialogConnexion()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialogConnexion(){

     dialogConnect->exec();
}


void MainWindow::connectToRobot()
{
    //this->ui->widget_CamStream->setUrl(infosLogin[1],infosLogin[3]);
    robotWifi->doConnect(infosLogin[0],infosLogin[2]);

    timerRefresh->start(50);
}

void MainWindow::disconnectToRobot()
{
    robotWifi->disConnect();
    timerRefresh->stop();
}

void MainWindow::getInfoDialogConnexion()
{
    infosLogin.clear();
    infosLogin.insert(0,dialogConnect->getTabInfoConnexion().at(0));
    infosLogin.insert(1,dialogConnect->getTabInfoConnexion().at(1));
    infosLogin.insert(2,dialogConnect->getTabInfoConnexion().at(2));
    infosLogin.insert(3,dialogConnect->getTabInfoConnexion().at(3));
    if(infosLogin.size()<4)
    {
        QMessageBox::critical(this, tr("Erreur!"),tr("Les informations de connexion ne sont pas valides"),
                                        QMessageBox::Ok);
    }
    else  connectToRobot();
}


void MainWindow::on_pushButton_2_pressed()
{
    robotWifi->sendRouler(vitesse);
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
       ui->label_Version->setText("Connexion en cours");
    }
    else
    {
        ui->label_Version->setText(robotWifi->getVersion());
        ui->label_BatterieValue->setText(robotWifi->getBatterie()+"%");
        ui->label_CaptInfra_AD->setText(QString::number(robotWifi->getIRAvantDroit()));
        ui->label_CaptInfra_AG->setText(QString::number(robotWifi->getIRAvantGauche()));
        ui->label_CaptInfra_BD->setText(QString::number(robotWifi->getIRArriereDroit()));
        ui->label_CaptInfra_BG->setText(QString::number(robotWifi->getIRArriereGauche()));
        ui->label_vitesseD->setText(QString::number(robotWifi->getVitesseDroite()));
        ui->label_vitesseG->setText(QString::number(robotWifi->getVitesseGauche()));
        ui->label_odometrieD->setText(QString::number(robotWifi->getOdometryDroite()));
        ui->label_odometrieG->setText(QString::number(robotWifi->getOdometryGauche()));





        if(batterie.toInt()>99)
           {
            ui->label_BatterieValue->setText("100%");

            }
        else
        {


            timerRefresh->start(50);
        }

    }
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    vitesse=value;
    this->ui->labelVitesse->setText(QString::number(vitesse));
}

void MainWindow::on_actionReconnexion_triggered()
{
    disconnectToRobot();
}
