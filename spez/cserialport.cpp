#include "cserialport.h"

CSerialPort::CSerialPort()
{
    serial = new QSerialPort();
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
        QMessageBox::critical(this, tr("Невозможно открыть порт"),
                              tr("Возможно порт занят"),
                              QMessageBox::Ok);
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
    QApplication::processEvents();
    if (serial->error())  qDebug()<<"Eror"<<serial->errorString()<<"   "<<serial->error();
    data = serial->readAll();
    if (statusPRIorSON==0)
    {
        if (status==0)
        {
            emit Signal_CSerialPort_SendDataToIFRNS(data);
        }
        if (status==1)
        {
            ;
        }
        if (status==2)
        {
            emit Signal_CSerialPort_SendDataToXModem(data);
        }
    }
    else if(statusPRIorSON==1)
    {
        if (status==0)
        {
            emit Signal_CSerialPort_SendDataToPRI(data);
        }
        if (status==1)
        {
            ;
        }
    }
    else if(statusPRIorSON==2)
    {
        if (status==0)
        {
            emit Signal_CSerialPort_SendDataToIFRNS_struct1(data);
        }
        if (status==1)
        {
            ;
        }
    }
}

void CSerialPort::Slot_Write_to_Com(QByteArray data1)
{
    serial->write(data1);
}
