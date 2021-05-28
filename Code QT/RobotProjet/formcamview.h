#ifndef FORMCAMVIEW_H
#define FORMCAMVIEW_H

#include <QWidget>
#include <QMediaPlayer>
//#include <QtWebEngine>

namespace Ui {
class FormCamView;
}

class FormCamView : public QWidget
{
    Q_OBJECT

public:
    explicit FormCamView(QWidget *parent = nullptr);
    ~FormCamView();
    void setUrlStream(QString newUrl);
private slots:

private:
    Ui::FormCamView *ui;
    QString urlStream;
};

#endif // FORMCAMVIEW_H
