#ifndef CSERIALPORT_H
#define CSERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class CSerialPort
{
public:
    CSerialPort();
    QList<QString> GiveAvaliableCom();

};

#endif // CSERIALPORT_H
