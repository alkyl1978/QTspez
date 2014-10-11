#ifndef CSERIALPORT_H
#define CSERIALPORT_H

#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>
#include <QMessageBox>

class CSerialPort
{
public:
    CSerialPort();
    QList<QString> GiveAvaliableCom();
    void Slot_CSerialProt_OpenComPort(QString name);
    void Slot_CSerialProt_CloseComPOrt();
    void Slot_ReadData_From_Com();
    void Slot_Write_to_Com(QByteArray data1);
    QSerialPort *serial;
    int statusPRIorSON;
    int status;

};

#endif // CSERIALPORT_H
