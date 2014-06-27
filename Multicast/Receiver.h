#ifndef RECEIVER_H
#define RECEIVER_H

#include <QHostAddress>
#include <QUdpSocket>

class Receiver: public QObject
{
    Q_OBJECT

public:
    Receiver(QObject *parent=0);

    QUdpSocket *udpSocket;
    QHostAddress groupAddress;

public slots:
    void processPendingDatagrams();


};

#endif // RECEIVER_H
