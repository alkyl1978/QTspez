#ifndef CSERIALPORT_H
#define CSERIALPORT_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class CSerialPort : public QObject
{
    Q_OBJECT
public:
    CSerialPort();
    QList<QString> GiveAvaliableCom(void);
public slots:
    void Slot_CSerialProt_OpenComPort(QString name);
    void Slot_CSerialProt_CloseComPOrt(void);
    void Slot_ReadData_From_Com(void);
    void Slot_Write_to_Com(QByteArray data1);
    void Slot_Error(QSerialPort::error err);
signals:
    void Signal_CSerialPort_SendDataToIFRNS(QByteArray data);
    void Signal_CSerialPort_OpenIsNormal();
    void Signal_CSerialPort_Error(QString error);
private:
    QSerialPort *serial;
};

#endif // CSERIALPORT_H
