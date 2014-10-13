#include "modbusadapter.h"
#include <QMessageBox>
#include <QtDebug>
#include <QMessageBox>


ModbusAdapter::ModbusAdapter(QObject *parent) :
    QObject(parent),
    m_modbus(NULL)
{
    m_connected=false;
}

void ModbusAdapter::modbusConnectRTU(QString port, int baud)
{

m_modbus=modbus_new_rtu(port.toStdString().c_str(), baud, 'N', 8, 1);

}
