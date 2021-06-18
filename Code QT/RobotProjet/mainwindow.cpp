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
    //map boutons dep rebot
    this->ui->pushButton_2->setIcon(QIcon("../../Images/Icons/chevron_up.svg"));
    this->ui->pushButtonReculer->setIcon(QIcon("../../Images/Icons/chevron_down.svg"));
    this->ui->pushButtonDroite->setIcon(QIcon("../../Images/Icons/chevron_right.svg"));
    this->ui->pushButtonGauche->setIcon(QIcon("../../Images/Icons/chevron_left.svg"));
    this->ui->pushButtonStopRobot->setIcon(QIcon("../../Images/Icons/square_stop.svg"));
    //map boutons dep cam
    this->ui->camHaut->setIcon(QIcon("../../Images/Icons/chevron_up.svg"));
    this->ui->camBas->setIcon(QIcon("../../Images/Icons/chevron_down.svg"));
    this->ui->camDroite->setIcon(QIcon("../../Images/Icons/chevron_right.svg"));
    this->ui->camGauche->setIcon(QIcon("../../Images/Icons/chevron_left.svg"));
    connect(timerRefresh, SIGNAL(timeout()), this, SLOT(refreshInfos()));
    connect(dialogConnect, SIGNAL(accepted()),this, SLOT(getInfoDialogConnexion()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Ouverture de la fenêtre de connexion*/
void MainWindow::openDialogConnexion(QAction *act){
    QString tempo = act->text();

    if(tempo=="Connexion")
    {
        dialogConnect->exec();
    }
    else {

        robotWifi->disConnect();
    }

}


void MainWindow::connectToRobot()
{
    robotWifi->doConnect(infosLogin[0],infosLogin[2]);
    this->ui->widget_CamStream->setCam(infosLogin[1], infosLogin[3]);
    this->ui->widget_CamStream->refreshURL();
    timerRefresh->start(50);
}

void MainWindow::disconnectToRobot()
{
    robotWifi->disConnect();
    timerRefresh->stop();
}

/*Récupération des infos du formulaire de la fenêtre de connexion*/
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

/*gestion des evt clavier*/
void MainWindow::keyPressEvent(QKeyEvent *event)
{

   if(event->key() == Qt::Key_Z)
   {
       robotWifi->sendRouler(vitesse);
   }
   else if(event->key() == Qt::Key_S)
   {
       robotWifi->sendReculer(vitesse);
   }
   else if(event->key() == Qt::Key_Q)
   {
       robotWifi->sendGauche(vitesse);
   }
   else if(event->key() == Qt::Key_D)
   {
       robotWifi->sendDroite(vitesse);
   }
   else if(event->key() == Qt::Key_I)
   {
       //haut
       this->ui->widget_CamStream->depCam_Haut();
   }
   else if(event->key() == Qt::Key_K)
   {
       //bas
       this->ui->widget_CamStream->depCam_Bas();
   }
   else if(event->key() == Qt::Key_J)
   {
       //gauche
       this->ui->widget_CamStream->depCam_Gauche();
   }
   else if(event->key() == Qt::Key_L)
   {
       //droite
       this->ui->widget_CamStream->depCam_Droite();
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

void MainWindow::on_camHaut_pressed()
{
    this->ui->widget_CamStream->depCam_Haut();
}

void MainWindow::on_camBas_pressed()
{
    this->ui->widget_CamStream->depCam_Bas();
}

void MainWindow::on_camGauche_pressed()
{
    this->ui->widget_CamStream->depCam_Gauche();
}

void MainWindow::on_camDroite_pressed()
{
    this->ui->widget_CamStream->depCam_Droite();
}
