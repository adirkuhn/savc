#include "Receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent): QObject(parent)
{
    groupAddress = QHostAddress("127.0.0.1");

    qDebug() << "Listening for multicasted messages";

    udpSocket = new QUdpSocket();
    udpSocket->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    udpSocket->joinMulticastGroup(groupAddress);

}

void Receiver::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        qDebug() << QString("Received datagram: \"%1\"").arg(datagram.data());
    }
}
