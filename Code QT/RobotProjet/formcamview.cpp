#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{
    ui->setupUi(this);
    this->depCam = new QNetworkAccessManager();
    //this->ui->cam->load(QUrl("http://192.168.1.11:8080/?action=stream"));
    this->ui->cam->setHtml("<image src='http://192.168.1.11:8080/?action=stream' width='100%' height='95%'/>");
    this->ui->camHaut->setIcon(QIcon("../../Images/Icons/chevron_up.svg"));
    this->ui->camBas->setIcon(QIcon("../../Images/Icons/chevron_down.svg"));
    this->ui->camDroite->setIcon(QIcon("../../Images/Icons/chevron_right.svg"));
    this->ui->camGauche->setIcon(QIcon("../../Images/Icons/chevron_left.svg"));
}

FormCamView::~FormCamView()
{
    delete ui;
}

void FormCamView::on_camHaut_pressed()
{
    this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200")));

}

void FormCamView::on_camBas_pressed()
{
    this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200")));
}

void FormCamView::on_camDroite_pressed()
{
    this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200")));
}

void FormCamView::on_camGauche_pressed()
{
    this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200")));
}

void FormCamView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_I)
    {
        //haut
        this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200")));
    }
    else if(event->key() == Qt::Key_K)
    {
        //bas
        this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200")));
    }
    else if(event->key() == Qt::Key_J)
    {
        //gauche
        this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200")));
    }
    else if(event->key() == Qt::Key_L)
    {
        //droite
        this->depCam->get(QNetworkRequest(QUrl("http://192.168.1.11:8080/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200")));
    }
}
