#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = nullptr);
    ~DialogConnexion();
    bool checkInfosInput();
   QVector<QString> getTabInfoConnexion();
private slots:
    void acceptInfoRobot();

    void on_buttonBox_accepted();

private:
    Ui::DialogConnexion *ui;
    QVector<QString> infosConnexion;
    QString ipRobot;
    QString ipCam;
    QString portRobot;
    QString portCam;
};

#endif // DIALOGCONNEXION_H
