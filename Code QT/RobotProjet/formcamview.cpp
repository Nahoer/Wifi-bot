#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent,QString ipCam,QString portCam) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{
    ui->setupUi(this);

}

/*Initialise l'URL de la cam et l'affiche*/
void FormCamView::setCam(QString ipCam, QString portCam){
    this->depCam = new QNetworkAccessManager();
    this->url="http://"+ipCam+":"+portCam;
    //this->ui->cam->load(QUrl("http://192.168.1.11:8080/?action=stream"));
    this->ui->cam->setHtml("<image src='"+url+"/?action=stream' width='100%' height='95%'/>");
}

FormCamView::~FormCamView()
{
    delete ui;
}

void FormCamView::depCam_Haut()
{
    this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200")));

}

void FormCamView::depCam_Bas()
{
    this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200")));
}

void FormCamView::depCam_Droite()
{
    this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200")));
}

void FormCamView::depCam_Gauche()
{
    this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200")));
}

void FormCamView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_I)
    {
        //haut
        this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094853&group=1&value=-200")));
    }
    else if(event->key() == Qt::Key_K)
    {
        //bas
        this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094853&group=1&value=200")));
    }
    else if(event->key() == Qt::Key_J)
    {
        //gauche
        this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094852&group=1&value=200")));
    }
    else if(event->key() == Qt::Key_L)
    {
        //droite
        this->depCam->get(QNetworkRequest(QUrl(url+"/?action=command&dest=0&plugin=0&id=10094852&group=1&value=-200")));
    }
}

void FormCamView::refreshURL(){
    this->ui->cam->reload();
}

void FormCamView::setOffline(){

    this->ui->cam->setHtml("<H1> OFFLINE</H1>");
}
