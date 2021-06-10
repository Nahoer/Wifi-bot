#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{

    ui->setupUi(this);
    //this->urlStream="<img src='https://helpx.adobe.com/content/dam/help/en/photoshop/using/convert-color-image-black-white/jcr_content/main-pars/before_and_after/image-before/Landscape-Color.jpg'/>";

    //this->ui->cam->load(QUrl("http://192.168.1.11:8080/?action=stream"));
    this->ui->cam->setHtml("<image src='http://192.168.1.11:8080/?action=stream' width='100%' height='95%'/>");
    //this->ui->cam->resize(461,331);
}

FormCamView::~FormCamView()
{
    delete ui;
}
