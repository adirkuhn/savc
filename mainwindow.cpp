#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->savcWidget = new SAVCWidget();
    this->savc = new SAVC();
    this->cilo = new CILO();

    ui->setupUi(this);
    this->setWindowTitle("SAVC");
    this->resize(600,400);

    //configura tela savc
    savcWidget->setupUi(this->ui->centralWidget);

    //TODO: Fazer Leitura dos dados do simulador
    qDebug() << "TODO: Fazer Leitura dos dados do simulador";

    //connect
    //leitura de pacotes
//    connect(receiver->udpSocket, SIGNAL(readyRead()),
//            receiver, SLOT(processPendingDatagrams()));

//    //atualizacao de dados recebidos
//    connect(receiver, SIGNAL(multicastReceivedData(QJsonObject)),
//            savcWidget, SLOT(savcUpdateData(QJsonObject)));
//    connect(receiver, SIGNAL(multicastReceivedData(QJsonObject)),
//            savc, SLOT(atualizaTensao(QJsonObject)));

    //escutar goose

    this->receiver = new Receiver(this);
    this->receiver->setCilo(cilo);
    this->receiver->start();
}

MainWindow::~MainWindow()
{
    //destroy thread
//    this->receiver->quit();
//    this->receiver->wait();
    this->receiver->terminate();
    while(!this->receiver->isFinished());

    delete this->savcWidget;
    delete this->receiver;
    delete this->savc;
    delete this->ui;

}
