#include "hexaarray.h"

HexaArray::HexaArray()
{
   this->array = QByteArray();
}

void HexaArray::FromByteArray(QByteArray array)
{
    this->array = array;
}

int HexaArray::getAsInt(int index)
{
    return array.at(index*2)+array.at(index*2+1);
}

