#ifndef HEXAARRAY_H
#define HEXAARRAY_H

#include <QTcpSocket>
#include <QObject>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>
#include <QIODevice>
#include <QDataStream>
#include <string>

class HexaArray
{
public:
    HexaArray();
    void FromByteArray(QByteArray);
    int getAsInt(int index);
    int asciiToInt(int index);
private:
    QByteArray array;


};

#endif // HEXAARRAY_H
