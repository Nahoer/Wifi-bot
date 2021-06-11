#ifndef MYROBOT_H
#define MYROBOT_H

#include <QTcpSocket>
#include <QObject>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QIODevice>
#include <QDataStream>
#include <string>
#include "hexaarray.h"

class MyRobot : public QObject {
    Q_OBJECT
public:

    explicit MyRobot(QObject *parent = 0);
    void doConnect(QString ip, QString port);
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;
    QString getVersion();
    QString getBatterie();
    void sendStop();
    void sendReculer(int vitesse);
    void sendDroite(int vitesse);
    void sendGauche(int vitesse);
    void sendRouler(int vitesse);
    QString traductionReponse(QByteArray reponse);
    bool estConnecter();
signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();
    quint16 Crc16(QByteArray tab, int pos);

    private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
    int batterieLevel;
    bool connecterAuRobot;
    int versionRobot;
    int IRAvantGauche;
    int IRAvantDroit;
    int IRArrièreGauche;
    int IRArrièreDroit;
    int odometryGauche;
    int odometryDroite;
    int vitesseGauche;
    int vitesseDroite;

};

#endif // MYROBOT_H
