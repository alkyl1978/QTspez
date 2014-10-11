#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
  connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Slot_click_push()));
}

void MainWindow::Slot_click_push()
{
    serport->Slot_CSerialProt_OpenComPort(comport);
}
