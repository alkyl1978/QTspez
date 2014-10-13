#ifndef MODBUSADAPTER_H
#define MODBUSADAPTER_H

#include <QObject>
#include <modbus/modbus.h>


class ModbusAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ModbusAdapter(QObject *parent = 0);
    void modbusConnectRTU(QString port, int baud);



private:
modbus_t* m_modbus;
bool m_connected;
signals:


public slots:


};

#endif // MODBUSADAPTER_H
