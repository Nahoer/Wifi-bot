#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>
#include <QMessageBox>

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

private slots:
    void acceptInfoRobot();

private:
    Ui::DialogConnexion *ui;
    QString infosConnexion[4];

};

#endif // DIALOGCONNEXION_H
