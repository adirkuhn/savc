#include "Receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent): QThread(parent)
{
//    groupAddress = QHostAddress("127.0.0.1");

//    qDebug() << "Listening for multicasted messages";

//    udpSocket = new QUdpSocket();
//    udpSocket->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
//    udpSocket->joinMulticastGroup(groupAddress);

    //escutar mensagens goose
    this->multicast = new Multicast();
}

Receiver::~Receiver()
{
    delete this->multicast;
}

void Receiver::run()
{
    qDebug() << "Escutar msg goose";
    //callback para "processar" os packets recebidos na rede
    this->multicast->listenMulticast(this->savcGoosePacketHandle, "ether proto 0x88b8 && ether[6:2] == 0x010C");
}

//processa pacotes recebidos da rede
void Receiver::savcGoosePacketHandle(u_char *args, const pcap_pkthdr *pkthdr, const u_char *packet)
{
    GooseMessage::goose_header *mgoose_header;
    mgoose_header = (struct GooseMessage::goose_header*) packet;

    qDebug() << "GOOSE HEADER SOURCE: " << ether_ntoa((const struct ether_addr *) mgoose_header->shost);
    qDebug() << "GOOSE HEADER DESTINATION:" << ether_ntoa((const struct ether_addr *) mgoose_header->dhost);

    //Decodifica mensagem
    asn_dec_rval_t result;
    IEC61850_8_1SpecificProtocol *gooseMessage;

    const unsigned char *payload = packet + sizeof(struct GooseMessage::goose_header);

    result = asn_DEF_IEC61850_8_1SpecificProtocol.ber_decoder(0, &asn_DEF_IEC61850_8_1SpecificProtocol, (void **) &gooseMessage, payload, mgoose_header->length, 0);

    if (result.code == RC_OK) {
        //Mensagem decodificada. Jogando resultado na GooseMessage
        GooseMessage *gm;
        gm = new GooseMessage();

        gm->setGocbRef(QString::fromLocal8Bit((const char *) gooseMessage->choice.goosePdu.gocbRef.buf));
        gm->setTimeAllowedtoLive(gooseMessage->choice.goosePdu.timeAllowedtoLive);
        gm->setDatSet(QString::fromLocal8Bit((const char *) gooseMessage->choice.goosePdu.datSet.buf));
        gm->setGoID(QString::fromLocal8Bit((const char *) gooseMessage->choice.goosePdu.goID->buf));
        gm->setT();
        gm->setStNum(gooseMessage->choice.goosePdu.stNum);

        qDebug() << gm->getGocbRef();
        qDebug() << gm->getTimeAllowedtoLive();
        qDebug() << gm->getDatSet();
        qDebug() << gm->getGoID();
        qDebug() << gm->getT();
        qDebug() << gm->getStNum();
        qDebug() << gm->getSqNum();
        qDebug() << gm->getTest();
        qDebug() << gm->getConfRev();
        qDebug() << gm->getNdsCom();
        qDebug() << gm->getNumDatSetEntries();

    }
    else {
        qDebug() << "Erro ao decodificar msg.";
    }
}
