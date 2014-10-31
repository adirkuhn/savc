#ifndef SENDER_H
#define SENDER_H

#include <QHostAddress>
#include <QtNetwork>
#include <QJsonArray>
#include <QJsonObject>

class Sender
{
private:
    QHostAddress groupAddress;
    QUdpSocket *udpSocket;
    int messageNo;

public:
    Sender();
    void sendDatagram(QJsonObject dataToSend);
    QJsonObject encodeData();
};

#endif // SENDER_H
