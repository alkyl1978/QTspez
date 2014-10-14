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
 //       if(m_connected)modbus_close(m_modbus);
        m_connected=false;
 //       modbus_free(m_modbus);
    }
    m_modbus=modbus_new_rtu(port.toStdString().c_str(), baud, 'N', 8, 1);
    modbus_set_slave(m_modbus, 0x0B);
}

void ModbusAdapter::modbusClose()
{
    if(m_connected)modbus_close(m_modbus);
    m_connected=false;
}

void ModbusAdapter::modbusConnect()
{
    uint8_t Status;
    if (m_modbus==NULL) return;
    if(!modbus_connect(m_modbus))
    {
        m_connected=true;
        modbus_read_registers(m_modbus, 50, 15, tab_reg);
        modbus_write_register(m_modbus,50,5);
    }
}

bool ModbusAdapter::modbusIsconnect()
{
    return m_connected;
}
