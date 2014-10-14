#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QSettings>
#include "modbusadapter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showSettingsModbusRTU();
public slots:

private:
    Ui::MainWindow *ui;
    QList<QString> GiveAvaliableCom();
    QSettings *ini;

};

#endif // MAINWINDOW_H
