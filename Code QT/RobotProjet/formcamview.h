#ifndef FORMCAMVIEW_H
#define FORMCAMVIEW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QImage>
#include <QWebEngineView>
#include<QtWebEngineWidgets>


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

private:
    Ui::FormCamView *ui;
};

#endif // FORMCAMVIEW_H
