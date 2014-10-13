#include "modbusadapter.h"
#include <QMessageBox>
#include <QtDebug>
#include <QMessageBox>

#include <errno.h>

ModbusAdapter *m_instance;

ModbusAdapter::ModbusAdapter(QObject *parent) :
    QObject(parent),
    m_modbus(NULL)
{

}
