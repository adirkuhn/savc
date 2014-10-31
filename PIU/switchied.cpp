#include "switchied.h"
#include "switchstatus.h"


SwitchIED::SwitchIED()
{
    this->XSWI1 = new XSWI();

    this->gooseMessage = new GooseMessage();

    this->gooseMessage->addSubscriber("a8:20:66:3b:f7:92");

    this->gooseMessage->setDatSet("DSLCC1");
    this->gooseMessage->setTimeAllowedtoLive(20);
    this->gooseMessage->setT();
    this->gooseMessage->setStNum(1);
    this->gooseMessage->setSqNum(1);
    this->gooseMessage->setTest(false);
    this->gooseMessage->setConfRev(1);
    this->gooseMessage->setNdsCom(false);
}

void SwitchIED::setLDName(QString name) {
    P_VISIBLE_STRING32 tmpName;
    tmpName.setValue(name);

    this->setName(tmpName);

    this->gooseMessage->setGocbRef("SEMD_" + name + "/LLN01/GoCBLCC1");
    this->gooseMessage->setGoID("SEMD_" + name + "/LLN01/GoCBLCC1");
}

QString SwitchIED::getLDName() {
    return this->getName().getObjectName().getValue();
}

void SwitchIED::setPos(int pos) {
    SwitchStatus switchStatus = SwitchStatus(SwitchStatus::enum_type(pos));
    //DPStatus dpStatus;
    BOOLEAN ctVal;
    P_BOOLEAN val;

    switch(switchStatus)
    {
        case SwitchStatus::offOrFalse:
            //dpStatus.setVal(offOrFalse);
            val.setVal(false);
            break;

        case SwitchStatus::intermediateState:
            //dpStatus.setVal(intermediateState);
            qDebug() << "TODO: Precisa implementar!!!";
            qDebug() << "TODO: Setando provisoriamente como false!!!";
            val.setVal(false);
            break;

        case SwitchStatus::badState:

            val.setVal(false);
            break;

        case SwitchStatus::onOrTrue:
            //dpStatus.setVal(onOrTrue);
            val.setVal(true);
            break;
    }

    ctVal.setVal(val);
    this->XSWI1->Pos.ctlVal.setAttr(ctVal);
    qDebug() << "Atribuido valor do Pos ao ctlVal. Agora precisa mudar posiçao do breaker e jogar o resultado em stVal";
    //this->XCBR1->Pos.stVal.setAttr(dpStatus);
    this->exec();
}

void SwitchIED::exec() {
    DPStatus dpStatus;

    dpStatus.setVal(offOrFalse);

    if (this->XSWI1->Pos.ctlVal.getAttr().getVal().getVal()) {
        dpStatus.setVal(onOrTrue);
    }

    //stVall
    this->XSWI1->Pos.stVal.setAttr(dpStatus);
}

int SwitchIED::getPos() {
    int val;
    DPStatusKind sk = this->XSWI1->Pos.stVal.getAttr().getVal();

    switch(sk) {
        case offOrFalse:
            val = 0;
            break;
        case intermediateState:
            val = 1;
            break;
        case badState:
            val = 2;
            break;
        case onOrTrue:
            val = 3;
            break;
    }

    return val;
}

//somente variante para alterar o endereço de mac
void SwitchIED::setMacAddress(int mac)
{
    //seta mac no campo disponivel em base 16
    QString maddr = QString("01:0C:CD:01:%1:C1").arg(mac, 2, 16, QChar('0'));

    this->gooseMessage->setMacAddress(maddr);
}

//envia msg goose
void SwitchIED::sendGoose()
{

    this->gooseMessage->setNumDatSetEntries(3);
    this->gooseMessage->cleanAllData();
    this->gooseMessage->addAllData(QString("%1").arg(this->getPos()));
    this->gooseMessage->addAllData(QString("%1").arg(1));
    this->gooseMessage->addAllData(QString("%1").arg(1));

    this->gooseMessage->sendMessageToSubscribers();
}

