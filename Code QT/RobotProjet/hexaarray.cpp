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

int HexaArray::asciiToInt(int index)
{
    std::string strbyte1 = "";
    strbyte1.push_back(+array.at(index*2));
    std::string strbyte2 = "";
    strbyte2.push_back(+array.at(index*2+1));
    int byte1 = stoi(strbyte1);
    int byte2 = stoi(strbyte2);

    return byte1*16 + byte2;

}
