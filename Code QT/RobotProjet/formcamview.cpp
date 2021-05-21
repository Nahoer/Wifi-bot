#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{

    ui->setupUi(this);
    this->urlStream="<img src='google.fr'/>";
    player.setMedia(QUrl(urlStream));
}

FormCamView::~FormCamView()
{
    delete ui;
}

void FormCamView::setUrlStream(QString newUrl)
{
    this->urlStream = "http://192.168.1.11:8080/?action=stream";
}


