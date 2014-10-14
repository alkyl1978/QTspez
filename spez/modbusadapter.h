#ifndef MODBUSADAPTER_H
#define MODBUSADAPTER_H

#include <QObject>
#include "modbus/inc/modbus.h"


class ModbusAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ModbusAdapter(QObject *parent = 0);
    void modbusSetPort(QString port, int baud);
    void modbusClose();
    void modbusConnect();
    bool modbusIsconnect();

private:
modbus_t* m_modbus;
bool m_connected;
signals:


public slots:


};

#endif // MODBUSADAPTER_H
