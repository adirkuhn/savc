#ifndef RECEIVER_H
#define RECEIVER_H

#include <QThread>
#include <GooseMessage.h>
#include "CILO.h"

class Receiver: public QThread
{
    Q_OBJECT

private:
    Multicast *multicast;
    static void savcGoosePacketHandle(u_char *args, const pcap_pkthdr *pkthdr, const u_char *packet);
    CILO *cilo;

public:
    Receiver(QObject *parent = 0);
    void setCilo(CILO *cilo);
    ~Receiver();
    void run();

};

#endif // RECEIVER_H
