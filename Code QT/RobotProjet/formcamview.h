#ifndef FORMCAMVIEW_H
#define FORMCAMVIEW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QImage>
#include <QWebEngineView>
#include<QNetworkAccessManager>


namespace Ui {
class FormCamView;
}

class FormCamView : public QWidget
{
    Q_OBJECT

public:
    explicit FormCamView(QWidget *parent = nullptr);
    ~FormCamView();


private slots:

    void on_camHaut_pressed();

private:
    Ui::FormCamView *ui;
    QNetworkAccessManager *depCam;
};

#endif // FORMCAMVIEW_H
