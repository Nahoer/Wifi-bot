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


class MyRobot : public QObject {
    Q_OBJECT
public:

    explicit MyRobot(QObject *parent = 0);
    void doConnect();
    void disConnect();
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;

signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();
    void sendRouler(int vitesse);
    void traductionReponse(QByteArray reponse);
    quint16 Crc16(QByteArray tab, int pos);
    void sendStop();
    void sendReculer(int vitesse);
    void sendDroite(int vitesse);
    void sendGauche(int vitesse);
    private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
};

#endif // MYROBOT_H
