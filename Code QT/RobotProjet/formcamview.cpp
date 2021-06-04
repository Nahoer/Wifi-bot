#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{
    ui->setupUi(this);
    //this->ui->cam->load(QUrl("http://192.168.1.11:8080/?action=stream"));
    this->ui->cam->setHtml("<image src='http://192.168.1.11:8080/?action=stream' width='100%' height='95%'/>");
}

FormCamView::~FormCamView()
{
    delete ui;
}
