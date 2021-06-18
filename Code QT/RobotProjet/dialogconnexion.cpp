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
    infosConnexion.insert(0,ui->lineEditIpRobot->text());
    infosConnexion.insert(1,ui->lineEditIpCamera->text());
    infosConnexion.insert(2,ui->lineEditPortRobot->text());
    infosConnexion.insert(3,ui->lineEditPortCamera->text());
    if(checkInfosInput()){
        emit this->accept();
    }
}

bool DialogConnexion::checkInfosInput(){
    bool valide(true);
    //Ligne IP robot
    if(!this->verifierIp(infosConnexion.at(1)))
    {
        QMessageBox::critical(this, tr("Erreur!"),tr("Le champs IP du robot n'est pas valide"),
                                                  QMessageBox::Ok);
        valide = false;
    }
    //Ligne IP camera
    if(!this->verifierIp(infosConnexion.at(0)))
    {
       QMessageBox::critical(this, tr("Erreur!"),tr("Le champs IP de la camera n'est pas valide"),
                                                  QMessageBox::Ok);
       valide=false;
    }
    //Port Robot
    if(!this->verifierPort(infosConnexion.at(2)))
    {
        QMessageBox::critical(this, tr("Erreur!"),tr("Le champs port du robot n'est pas valide"),
                                                   QMessageBox::Ok);
        valide=false;
    }
    //Port Camera
    if(!this->verifierPort(infosConnexion.at(3)))
    {
        QMessageBox::critical(this, tr("Erreur!"), tr("Le champs port de la camera n'est pas valide"),
                                                   QMessageBox::Ok);
        valide=false;
    }
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

bool DialogConnexion::verifierPort(QString port)
{
    bool portValide=true;
    if(port.size()>0&&port.size()<6)
    {
        for(int i=0; i<port.size();i++)
        {
            if(port.at(i)<48 || port.at(i)>57)
            {
                portValide=false;
            }
        }
    }
    else portValide =false;

    return portValide;
}

bool DialogConnexion::verifierIp(QString ip)
{
    bool ipValide=true;
    if(ip.size()>0&&ip.size()<16)
    {
        for(int i=0; i<ip.size();i++)
        {
            QChar c = ip.at(i);
            if((c<48 || c>57) && c!=46)
            {
                ipValide=false;
            }
        }
    }
    else ipValide=false;
    return ipValide;
}
