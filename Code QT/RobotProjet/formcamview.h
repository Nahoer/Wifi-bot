#ifndef FORMCAMVIEW_H
#define FORMCAMVIEW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QImage>
#include <QWebEngineView>
#include<QNetworkAccessManager>
#include <QKeyEvent>


namespace Ui {
class FormCamView;
}

class FormCamView : public QWidget
{
    Q_OBJECT

public:
    explicit FormCamView(QWidget *parent = nullptr,QString ipCam="",QString portCam="");
    void setCam(QString ipCam, QString portCam);
    void refreshURL();
    void setOffline();
    void depCam_Haut();

    void depCam_Bas();

    void depCam_Droite();

    void depCam_Gauche();
    ~FormCamView();


private slots:





    void keyPressEvent(QKeyEvent *);
    //void keyReleaseEvent(QKeyEvent *);


private:
    Ui::FormCamView *ui;
    QNetworkAccessManager *depCam;
    QString url;
};

#endif // FORMCAMVIEW_H
