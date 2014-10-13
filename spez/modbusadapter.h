#ifndef MODBUSADAPTER_H
#define MODBUSADAPTER_H

#include <QObject>
#include <modbus/modbus.h>


class ModbusAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ModbusAdapter(QObject *parent = 0);


private:
modbus_t* m_modbus;
signals:


public slots:


};

#endif // MODBUSADAPTER_H
