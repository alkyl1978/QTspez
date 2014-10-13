#include "cserialport.h"

 CSerialPort::CSerialPort()
{
    serial=new QSerialPort();
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

void CSerialPort::Slot_CSerialProt_OpenComPort(QString name)
{
    //устанавливаем настройки Com
    serial->setPortName(name);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "Open is normal" ;
        emit Signal_CSerialPort_OpenIsNormal();
    }
    else
    {
       qDebug() << "Error" ;
       emit Signal_CSerialPort_Error(serial->errorString());
    }
}


void CSerialPort::Slot_CSerialProt_CloseComPOrt()
{
    serial->close();
    qDebug()<< "Close is normal" ;
}

void CSerialPort::Slot_ReadData_From_Com()
{
    QByteArray data;
    if (serial->error())
    {
        qDebug()<<"Eror"<<serial->errorString()<<"   "<<serial->error();
        emit Signal_CSerialPort_Error(serial->errorString());
    }
    data = serial->readAll();
}

void CSerialPort::Slot_Error(QSerialPort::error err)
{

}

void CSerialPort::Slot_Write_to_Com(QByteArray data1)
{
    serial->write(data1);
    if(serial->error())
    {
        qDebug() << "Write is normal" ;
    }
    else
    {
        qDebug()<<"Eror"<<serial->errorString()<<"   "<<serial->error();
        emit Signal_CSerialPort_Error(serial->errorString());

    }
}
