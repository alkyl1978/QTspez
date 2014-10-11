#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openport=0;
    serport=new CSerialPort();
    ui->comboBox->addItems(serport->GiveAvaliableCom());
    connect(ui->comboBox, SIGNAL(activated(QString)),this,SLOT(Slot_change_combo(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Slot_change_combo(QString text)
{
  comport=text;
  ui->pushButton->setEnabled(true);
  connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Slot_click_push()));
  connect(serport,SIGNAL(Signal_CSerialPort_OpenIsNormal()),this,SLOT(Slot_openISNormal()));
}

void MainWindow::Slot_click_push()
{
    if(openport)
    {
        serport->Slot_CSerialProt_CloseComPOrt();
        ui->pushButton->setText("Открыть Порт");
        openport=0;
    }
    else
    {
        serport->Slot_CSerialProt_OpenComPort(comport);
    }
}

void MainWindow::Slot_openISNormal()
{
    ui->pushButton->setText("Закрыть Порт");
    openport=1;
}
