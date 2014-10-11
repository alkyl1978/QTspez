#include "cserialport.h"

CSerialPort::CSerialPort()
{
}


QList<QString> CSerialPort::GiveAvaliableCom()
{
    QList<QString> List_Settings;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        List_Settings.append(info.portName());
    }
    return List_Settings;
}
