#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->receiver = new Receiver();
    this->savcWidget = new SAVCWidget();

    ui->setupUi(this);
    this->setWindowTitle("SAVC");
    this->resize(600,400);

    //configura tela savc
    savcWidget->setupUi(this->ui->centralWidget);

    //TODO: Fazer Leitura dos dados do simulador
    qDebug() << "TODO: Fazer Leitura dos dados do simulador";

    //connect
    //leitura de pacotes
    connect(receiver->udpSocket, SIGNAL(readyRead()),
            receiver, SLOT(processPendingDatagrams()));

    //atualizacao de dados recebidos
    connect(receiver, SIGNAL(multicastReceivedData(QJsonObject)),
            savcWidget, SLOT(savcUpdateData(QJsonObject)));
}

MainWindow::~MainWindow()
{
    delete savcWidget;
    delete receiver;
    delete ui;

}
