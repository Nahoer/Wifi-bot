#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}


void DialogConnexion::acceptInfoRobot()
{
    infosConnexion.clear();
    infosConnexion.insert(0,ui->lineEditIpCamera->text());
    infosConnexion.insert(1,ui->lineEditIpRobot->text());
    infosConnexion.insert(2,ui->lineEditPortRobot->text());
    infosConnexion.insert(3,ui->lineEditPortCamera->text());
    if(checkInfosInput()){
        emit this->accept();
    }
}

bool DialogConnexion::checkInfosInput(){
    bool valide(true);
    //Ligne IP robot
    /*if(!this->verifierIp(infosConnexion.at(1)))
    {
        QMessageBox::critical(this, tr("!!!!Erreur!!!!"),
                                                  tr("Le champs IP du robot contient une erreur"),
                                                  QMessageBox::Ok);
        valide = false;
    }
    //Ligne IP camera
    if(!this->verifierIp(infosConnexion.at(0)))
    {
       QMessageBox::critical(this, tr("!!!!Erreur!!!!"),
                                                  tr("Le champs IP de la camera contient une erreur"),
                                                  QMessageBox::Ok);
       valide=false;
    }
    //Port Robot
    if(!this->verifierPort(infosConnexion.at(2)))
    {
        QMessageBox::critical(this, tr("!!!!Erreur!!!!"),
                                                   tr("Le champs IP de la camera contient une erreur"),
                                                   QMessageBox::Ok);
        valide=false;
    }
    //Port Camera
    if(!this->verifierPort(infosConnexion.at(2)))
    {
        QMessageBox::critical(this, tr("!!!!Erreur!!!!"),
                                                   tr("Le champs IP de la camera contient une erreur"),
                                                   QMessageBox::Ok);
        valide=false;
    }*/
    return valide;
}

QVector<QString> DialogConnexion::getTabInfoConnexion()
{
    return infosConnexion;
}

void DialogConnexion::on_buttonBox_accepted()
{
    acceptInfoRobot();
}
