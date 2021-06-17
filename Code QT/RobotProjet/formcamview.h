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
    explicit FormCamView(QWidget *parent = nullptr);
    ~FormCamView();


private slots:

    void on_camHaut_pressed();

    void on_camBas_pressed();

    void on_camDroite_pressed();

    void on_camGauche_pressed();

    void keyPressEvent(QKeyEvent *);
    //void keyReleaseEvent(QKeyEvent *);


private:
    Ui::FormCamView *ui;
    QNetworkAccessManager *depCam;
};

#endif // FORMCAMVIEW_H
