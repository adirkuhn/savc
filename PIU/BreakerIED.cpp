#include "BreakerIED.h"

//TODO verificar se os demais XCBR devem copiar as informações do primeiro

BreakerIED::BreakerIED()
{
    //sao 3 XCBR pois o sistema é trifasico
    this->XCBR1 = new XCBR();
    this->XCBR2 = new XCBR();
    this->XCBR3 = new XCBR();

    this->gooseMessage = new GooseMessage();
    this->gooseMessage2 = new GooseMessage();
    this->gooseMessage3 = new GooseMessage();
}

void BreakerIED::setLDName(QString name) {
    P_VISIBLE_STRING32 tmpName;
    tmpName.setValue(name);

    this->setName(tmpName);

    this->gooseMessage->setGocbRef("SEMD_" + name + "/LLN01/GoCBLCD1");
    this->gooseMessage->setGoID("SEMD_" + name + "/LLN01/GoCBLCD1");

    this->gooseMessage2->setGocbRef("SEMD_" + name + "/LLN01/GoCBLCE1");
    this->gooseMessage2->setGoID("SEMD_" + name + "/LLN01/GoCBLCE1");

    this->gooseMessage3->setGocbRef("SEMD_" + name + "/LLN01/GoCBLCF1");
    this->gooseMessage3->setGoID("SEMD_" + name + "/LLN01/GoCBLCF1");
}

QString BreakerIED::getLDName() {
    return this->getName().getObjectName().getValue();
}

void BreakerIED::setPos(int pos) {
    BreakerStatus breakerStatus = BreakerStatus(BreakerStatus::enum_type(pos));
    //DPStatus dpStatus;
    BOOLEAN ctVal;
    P_BOOLEAN val;

    switch(breakerStatus)
    {
        case BreakerStatus::open:
            //dpStatus.setVal(offOrFalse);
            val.setVal(false);
            break;

        case BreakerStatus::half_open:
            //dpStatus.setVal(intermediateState);
            qDebug() << "TODO: Precisa implementar!!!";
            qDebug() << "TODO: Setando provisoriamente como false!!!";
            val.setVal(false);
            break;

        case BreakerStatus::closed:
            //dpStatus.setVal(onOrTrue);
            val.setVal(true);
            break;
    }

    ctVal.setVal(val);
    this->XCBR1->Pos.ctlVal.setAttr(ctVal);
    qDebug() << "Atribuido valor do Pos ao ctlVal. Agora precisa mudar posiçao do breaker e jogar o resultado em stVal";
    //this->XCBR1->Pos.stVal.setAttr(dpStatus);
    this->exec();
}

//TODO: Mudar a posiçao do breaker e setar valor no stVal
void BreakerIED::exec() {
    DPStatus dpStatus;

    dpStatus.setVal(offOrFalse);

    if (this->XCBR1->Pos.ctlVal.getAttr().getVal().getVal()) {
        dpStatus.setVal(onOrTrue);
    }

    //stVal
    this->XCBR1->Pos.stVal.setAttr(dpStatus);
}

int BreakerIED::getPos() {
    int val;
    DPStatusKind sk = this->XCBR1->Pos.stVal.getAttr().getVal();

    switch(sk) {
        case offOrFalse:
            val = 0;
            break;
        case intermediateState:
            val = 1;
            break;
        case onOrTrue:
            val = 2;
            break;
    }

    return val;
}

//somente variante para alterar o endereço de mac
void BreakerIED::setMacAddress(int mac)
{
    //seta mac no campo disponivel em base 16
    QString maddr = QString("01:0C:CD:01:%1:D1").arg(mac, 2, 16, QChar('0'));
    QString maddr2 = QString("01:0C:CD:01:%1:E1").arg(mac, 2, 16, QChar('0'));
    QString maddr3 = QString("01:0C:CD:01:%1:F1").arg(mac, 2, 16, QChar('0'));

    this->gooseMessage->setMacAddress(maddr);
    this->gooseMessage2->setMacAddress(maddr2);
    this->gooseMessage3->setMacAddress(maddr3);
}

//envia msg goose
void BreakerIED::sendGoose()
{
//    //b1
//    this->gooseMessage->setNumDatSetEntries(3);
//    this->gooseMessage->cleanAllData();
//    this->gooseMessage->addAllData(QString("%1").arg(this->getPos()));
//    this->gooseMessage->addAllData(QString("%1").arg(1));
//    this->gooseMessage->addAllData(QString("%1").arg(1));
//    //b2
//    this->gooseMessage2->setNumDatSetEntries(3);
//    this->gooseMessage2->cleanAllData();
//    this->gooseMessage2->addAllData(QString("%1").arg(this->getPos()));
//    this->gooseMessage2->addAllData(QString("%1").arg(1));
//    this->gooseMessage2->addAllData(QString("%1").arg(1));
//    //b3
//    this->gooseMessage3->setNumDatSetEntries(3);
//    this->gooseMessage3->cleanAllData();
//    this->gooseMessage3->addAllData(QString("%1").arg(this->getPos()));
//    this->gooseMessage3->addAllData(QString("%1").arg(1));
//    this->gooseMessage3->addAllData(QString("%1").arg(1));

//    this->gooseMessage->sendMessageToSubscribers();
//    this->gooseMessage2->sendMessageToSubscribers();
//    this->gooseMessage3->sendMessageToSubscribers();
}
