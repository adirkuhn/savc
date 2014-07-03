#ifndef RECEIVER_H
#define RECEIVER_H

#include <QHostAddress>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonObject>

class Receiver: public QObject
{
    Q_OBJECT

public:
    Receiver(QObject *parent=0);

    QUdpSocket *udpSocket;
    QHostAddress groupAddress;

public slots:
    void processPendingDatagrams();

private:
    QJsonObject decodeReceivedData(QByteArray receivedData);

signals:
    //void receivedData(const QJsonObject &);
    void multicastReceivedData(QJsonObject);

};

#endif // RECEIVER_H
