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
    if(checkInfosInput()){
        infosConnexion.insert(0,(ui->lineEditIpCamera->text()));
        infosConnexion.insert(1,ui->lineEditIpRobot->text());
        infosConnexion.insert(2,ui->lineEditPortRobot->text());
        infosConnexion.insert(3,ui->lineEditPortCamera->text());
        emit this->accept();
    }
}

bool DialogConnexion::checkInfosInput(){
    bool valide(true);
    /*int ret = QMessageBox::critical(this, tr("Erreur"),
                                          tr("Un champ est vide ou mal saisi"),
                                          QMessageBox::Ok);
    */
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
