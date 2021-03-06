// myrobot.cpp

#include "myrobot.h"

MyRobot::MyRobot(QObject *parent) : QObject(parent) {
    connecterAuRobot = false;
    DataToSend.resize(9);
    DataToSend[0] = 0xFF;
    DataToSend[1] = 0x07;
    DataToSend[2] = 0x0;
    DataToSend[3] = 0x0;
    DataToSend[4] = 0x0;
    DataToSend[5] = 0x0;
    DataToSend[6] = 0x0;
    DataToSend[7] = 0x0;
    DataToSend[8] = 0x0;

    DataReceived.resize(21);
    TimerEnvoi = new QTimer();
    // setup signal and slot
    connect(TimerEnvoi, SIGNAL(timeout()), this, SLOT(MyTimerSlot())); //Send data to wifibot timer
}

quint16 MyRobot::Crc16(QByteArray tab, int pos)
{
   tab.data();
   unsigned char *data = (unsigned char*)tab.constData();
   quint16 crc=0xFFFF;
   quint16 Polynome = 0xA001;
   quint16 Parity = 0;
   for(; pos<tab.length();pos++)
   {
       crc ^= *(data+pos);
       for(unsigned int CptBit=0; CptBit<=7;CptBit++)
       {
           Parity=crc;
           crc >>=1;
           if(Parity%2==true)crc ^=Polynome;
       }
   }

    return crc;
}



void MyRobot::doConnect(QString ip, QString port) {
    socket = new QTcpSocket(this); // socket creation
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    qDebug() << "connecting..."; // this is not blocking call
    socket->connectToHost(ip, port.toInt()); // connection to wifibot
    //socket->connectToHost("192.168.1.11", 15020);
    // we need to wait...
    if(!socket->waitForConnected(5000)) {
        qDebug() << "Error: " << socket->errorString();
        return;
    }
    TimerEnvoi->start(75);

}

void MyRobot::disConnect() {
    TimerEnvoi->stop();
    socket->close();
}

void MyRobot::connected() {
    qDebug() << "connected..."; // Hey server, tell me about you.
    connecterAuRobot=true;
}

void MyRobot::disconnected() {
    qDebug() << "disconnected...";
}

void MyRobot::bytesWritten(qint64 bytes) {
    qDebug() << bytes << " bytes written...";
}

void MyRobot::readyRead() {
    qDebug() << "reading..."; // read the data from the socket
    DataReceived = socket->readAll();
    emit updateUI(DataReceived);
    HexaArray response = HexaArray();
    response.FromByteArray(DataReceived.toHex());
    batterieLevel= response.getAsInt(2);
    IRAvantGauche = response.getAsInt(3);
    IRArriereGauche = response.getAsInt(4);
    IRAvantDroit = response.getAsInt(11);
    IRArriereDroit = response.getAsInt(12);
    versionRobot = response.asciiToInt(18);
    odometryGauche = response.getAsInt(5)+response.getAsInt(6)+response.getAsInt(7)+response.getAsInt(8);
    odometryDroite = response.getAsInt(16)+response.getAsInt(15)+response.getAsInt(14)+response.getAsInt(13);
    vitesseGauche = response.getAsInt(0)+response.getAsInt(1);
    vitesseDroite = response.getAsInt(10)+response.getAsInt(9);

}

void MyRobot::MyTimerSlot() {
    qDebug() << "Timer...";
    while(Mutex.tryLock());
    socket->write(DataToSend);
    Mutex.unlock();
}

/*M??thode pour faire avancer le robot en fonction des param??tres (vitesse, etc*/
void MyRobot::sendRouler(int vitesse)
{
    unsigned char zero=0;
    while(Mutex.tryLock());
    DataToSend.clear();
    DataToSend.append(0xFF);
    DataToSend.append(0x07);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(0x50);
    quint16 crcsend = Crc16(DataToSend,1);
    DataToSend[7] = crcsend;
    DataToSend[8] = crcsend>>8;

    Mutex.unlock();
}

/*M??thode pour arr??ter le robot en fonction des param??tres (vitesse, etc*/
void MyRobot::sendStop()
{
    unsigned char zero =0;
    while(Mutex.tryLock());
    DataToSend.clear();
    DataToSend.append(0xFF);
    DataToSend.append(0x07);
    DataToSend.append(zero);
    DataToSend.append(zero);
    DataToSend.append(zero);
    DataToSend.append(zero);
    DataToSend.append(zero);
    quint16 crcsend = Crc16(DataToSend,1);
    DataToSend[7] = crcsend;
    DataToSend[8] = crcsend>>8;
    Mutex.unlock();
}

/*M??thode pour faire reculer le robot en fonction des param??tres (vitesse, etc*/
void MyRobot::sendReculer(int vitesse)
{
    unsigned char zero =0;
    while(Mutex.tryLock());
    DataToSend.clear();
    DataToSend.append(0xFF);
    DataToSend.append(0x07);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(zero);
    quint16 crcsend = Crc16(DataToSend,1);
    DataToSend[7] = crcsend;
    DataToSend[8] = crcsend>>8;

    Mutex.unlock();
}

/*M??thode pour faire tourner le robot ?? gauche en fonction des param??tres (vitesse, etc*/
void MyRobot::sendGauche(int vitesse)
{
    unsigned char zero =0;
    DataToSend.clear();
    DataToSend.append(0xFF);
    DataToSend.append(0x07);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(0x10);
    quint16 crcsend = Crc16(DataToSend,1);
    DataToSend[7] = crcsend;
    DataToSend[8] = crcsend>>8;
}

/*M??thode pour faire tourner le robot ?? droite en fonction des param??tres (vitesse, etc*/
void MyRobot::sendDroite(int vitesse)
{
    unsigned char zero =0;
    DataToSend.clear();
    DataToSend.append(0xFF);
    DataToSend.append(0x07);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(vitesse);
    DataToSend.append(zero);
    DataToSend.append(0x40);
    quint16 crcsend = Crc16(DataToSend,1);
    DataToSend[7] = crcsend;
    DataToSend[8] = crcsend>>8;
}




QString MyRobot::traductionReponse(QByteArray reponse)
{
    qDebug()<<"Message recu :";
    qDebug()<<reponse.toHex();
    return reponse;
}

QString MyRobot::getBatterie()
{

    return QString::number(batterieLevel);
}

QString MyRobot::getVersion()
{

    return QString::number(versionRobot);
}

bool MyRobot::estConnecter()
{
    return connecterAuRobot;
}

int MyRobot::getIRAvantDroit()
{
    return this->IRAvantDroit;
}

int MyRobot::getIRAvantGauche()
{
    return this->IRAvantGauche;
}

int MyRobot::getIRArriereDroit()
{
   return this->IRArriereDroit;
}

int MyRobot::getIRArriereGauche()
{
    return this->IRArriereGauche;
}

int MyRobot::getOdometryDroite()
{
    return this->odometryDroite;
}

int MyRobot::getOdometryGauche()
{
    return this->odometryGauche;
}

int MyRobot::getVitesseDroite()
{
    return this->vitesseDroite;
}

int MyRobot::getVitesseGauche()
{
    return this->vitesseGauche;
}
