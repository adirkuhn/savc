#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <GUI/SAVCWidget.h>
#include <Multicast/Receiver.h>
#include <SAVC.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Receiver *receiver;
    SAVCWidget *savcWidget;
    SAVC *savc;
    QThread *thread;
    CILO *cilo;

};

#endif // MAINWINDOW_H
