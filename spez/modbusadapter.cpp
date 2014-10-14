#include "modbusadapter.h"
#include <QMessageBox>
#include <QtDebug>
#include <QMessageBox>


ModbusAdapter::ModbusAdapter(QObject *parent) :
    QObject(parent),
    m_modbus(NULL)
{
    m_connected=false;
    m_modbus=NULL;
}

void ModbusAdapter::modbusSetPort(QString port)
{
   comport= port;
}

void ModbusAdapter::modbusClose()
{
    if(m_connected)modbus_close(m_modbus);
    m_connected=false;
}

void ModbusAdapter::modbusConnect()
{

}

bool ModbusAdapter::modbusIsconnect()
{
    return m_connected;
}
