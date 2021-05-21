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
    /*if(checkInfosInput()){
        QString ipCam=ui->lineEditIpCamera->text();
        QString ipRobot=ui->lineEditIpRobot->text();
        QString portRobot=ui->lineEditPortRobot->text();
        QString portCam=ui->lineEditPortCamera->text();
        this->parent()->getInfoDialogConnexion();
        this->accept();
    }*/

}

bool DialogConnexion::checkInfosInput(){
    bool valide(true);
    /*int ret = QMessageBox::critical(this, tr("Erreur"),
                                          tr("Un champ est vide ou mal saisi"),
                                          QMessageBox::Ok);*/

    return valide;
}
