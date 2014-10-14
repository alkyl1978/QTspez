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

void ModbusAdapter::modbusSetPort(QString port, int baud)
{
    if(m_modbus!=NULL)
    {
        modbus_free(m_modbus);
        m_connected=false;
    }
    m_modbus=modbus_new_rtu(port.toStdString().c_str(), baud, 'N', 8, 1);
}

void ModbusAdapter::modbusClose()
{
    if(m_connected)modbus_close(m_modbus);
    m_connected=false;
}

void ModbusAdapter::modbusConnect()
{
    if (m_modbus==NULL) return;
    if(!modbus_connect(m_modbus)) m_connected=true;
}

bool ModbusAdapter::modbusIsconnect()
{
    return m_connected;
}
