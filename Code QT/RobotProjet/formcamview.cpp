#include "formcamview.h"
#include "ui_formcamview.h"

FormCamView::FormCamView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCamView)
{

    ui->setupUi(this);
    this->urlStream="<img src='https://helpx.adobe.com/content/dam/help/en/photoshop/using/convert-color-image-black-white/jcr_content/main-pars/before_and_after/image-before/Landscape-Color.jpg'/>";
    //QWebChannel test(this);
    /*webview = new QWebView;
    QUrl url("http://192.168.1.11:8080/?action=stream");
    webview->load(url);
    webview->show();*/
    player = new QMediaPlayer;
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setMedia(QUrl("http://192.168.1.11:8080/?action=stream"));
    videoWidget = new QVideoWidget;
}

FormCamView::~FormCamView()
{
    delete ui;
}

void FormCamView::setUrlStream(QString newUrl)
{
    this->urlStream = "http://192.168.1.11:8080/?action=stream";
}



