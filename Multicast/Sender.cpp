#include "Sender.h"
#include <QDebug>

Sender::Sender()
{
    groupAddress = QHostAddress("127.0.0.1");
    messageNo = 1;
    udpSocket = new QUdpSocket;

    qDebug() << QString("Ready to multicast datagrams to group %1 on port 45455.").arg(groupAddress.toString());

}

void Sender::sendDatagram(QJsonObject dataToSend) {
    QJsonDocument jsonDocument(dataToSend);

    qDebug() << QString("Now sending datagram %1.").arg(messageNo);

    //QByteArray datagram = "Multicast message " + QByteArray::number(messageNo);
    QByteArray datagram = jsonDocument.toJson();

    qDebug() << datagram;

    udpSocket->writeDatagram(datagram, datagram.size(), groupAddress, 45455);
    messageNo++;
}

QJsonObject Sender::encodeData() {
    QJsonObject object;

    qDebug() << object;

    return object;
}
