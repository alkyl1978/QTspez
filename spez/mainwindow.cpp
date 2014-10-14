#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ini=new QSettings("setting.ini",QSettings::IniFormat);
    ui->setupUi(this);
    ui->comboBox->addItems(GiveAvaliableCom());
    if(ui->comboBox->count())
    {
        ui->pushButton->setEnabled(true);
    }
    ui->vSlid_X->setValue(ini->value("Servo/X",0).toInt());
    ui->vSlid_Y->setValue(ini->value("Servo/Y",0).toInt());
    ui->vSlid_Z->setValue(ini->value("Servo/Z",0).toInt());
    modbus= new ModbusAdapter;
  // modbus->modbusSetPort(ui->comboBox->currentText().toStdString().c_str(),115200);
}

MainWindow::~MainWindow()
{
    ini->setValue("Servo/X",ui->vSlid_X->value());
    ini->setValue("Servo/Y",ui->vSlid_Y->value());
    ini->setValue("Servo/Z",ui->vSlid_Z->value());
    ini->sync();
    delete ui;
}

QList<QString> MainWindow::GiveAvaliableCom()
{
    QList<QString> List_Settings;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        List_Settings.append(info.portName());
    }
    return List_Settings;
}


void MainWindow::on_pushButton_clicked()
{
    if(!modbus->modbusIsconnect())
    {
        modbus->modbusConnect();
    }
    else
    {
        modbus->modbusClose();
    }
    if(modbus->modbusIsconnect()) ui->pushButton->setText(tr("Закрыть порт"));
    else ui->pushButton->setText(tr("Открыть порт"));
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
 modbus->modbusSetPort(arg1.toStdString().c_str(),115200);
 if(modbus->modbusIsconnect()) ui->pushButton->setText(tr("Закрыть порт"));
 else ui->pushButton->setText(tr("Открыть порт"));
}
