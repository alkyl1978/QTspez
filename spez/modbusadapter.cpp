#include "modbusadapter.h"
#include <QMessageBox>
#include <QtDebug>
#include <QMessageBox>


ModbusAdapter::ModbusAdapter(QObject *parent) :
    QObject(parent),
    m_modbus(NULL)
{

}
