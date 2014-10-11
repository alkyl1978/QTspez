#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void Slot_change_combo(QString text);
    void Slot_click_push();
    void Slot_openISNormal();
private:
    Ui::MainWindow *ui;
    CSerialPort *serport;
    QString comport;
    int openport;
};

#endif // MAINWINDOW_H
