#ifndef CSERIALPORT_H
#define CSERIALPORT_H

#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>
#include <QMessageBox>


class CSerialPort
{
    Q_OBJECT
public:

public slots:
    void Slot_CSerialProt_OpenComPort(QString name);
    void Slot_CSerialProt_CloseComPOrt(void);
    void Slot_ReadData_From_Com(void);
    void Slot_Write_to_Com(QByteArray data1);
signals:
    void Signal_CSerialPort_SendDataToIFRNS(QByteArray data);
private:
    QSerialPort *serial;
    QList<QString> GiveAvaliableCom(void);
};

#endif // CSERIALPORT_H
