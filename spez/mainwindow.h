#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>

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

};

#endif // MAINWINDOW_H
