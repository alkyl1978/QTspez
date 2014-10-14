#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ini=new QSettings("setting.ini",QSettings::NativeFormat);
    ui->setupUi(this);
    ui->comboBox->addItems(GiveAvaliableCom());
    if(ui->comboBox->count())
    {
        ui->pushButton->setEnabled(true);
    }
}

MainWindow::~MainWindow()
{
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

