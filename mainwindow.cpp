#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    SAVCWidget *savcWidget = new SAVCWidget;

    this->receiver = new Receiver();

    ui->setupUi(this);
    this->setWindowTitle("SAVC");
    this->resize(600,400);

    //configura tela savc
    savcWidget->setupUi(this->ui->centralWidget);

    //TODO: Fazer Leitura dos dados do simulador
    qDebug() << "TODO: Fazer Leitura dos dados do simulador";

    //connect
    connect(receiver->udpSocket, SIGNAL(readyRead()),
            receiver, SLOT(processPendingDatagrams()));
}

MainWindow::~MainWindow()
{
    delete receiver;
    delete ui;

}
