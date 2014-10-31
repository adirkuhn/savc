#include "SAVC.h"

//Params
const float SAVC::bandaMorta = 2.0;
const float SAVC::tensaoBaixaAceitavel = 220.0 - SAVC::bandaMorta;
const float SAVC::tensaoAltaAceitavel = 220.0 + SAVC::bandaMorta;

SAVC::SAVC()
{

    this->speATCC = new ATCC;
    this->mmxu1 = new MMXU;
    this->mmxu2 = new MMXU;

    this->sender = new Sender;

    this->tensaoBarra220kv = -1;
    this->tensaoBarra500kv = -1;
}

SAVC::~SAVC() {
    delete this->speATCC;
    delete this->mmxu1;
    delete this->mmxu2;

    delete this->sender;
}

void SAVC::verificaTensao() {
    qDebug() << "Verificando Tensao";
    qDebug() << "=========================";
    qDebug() << this->tensaoBarra220kv;

    if (this->tensaoBarra220kv < this->tensaoBaixaAceitavel) {
        //Sobe Tap
        qDebug() << "Sobe tap +1";
        this->mudaTap(1);
    }
    else if (this->tensaoBarra220kv > this->tensaoAltaAceitavel) {
        //baixa Tap
        qDebug() << "Baixa tap -1";
        this->mudaTap(-1);
    }
}

//Envia comando para subir tap na rede
void SAVC::mudaTap(short int tapPos) {
    QJsonObject comando;

    if (tapPos == 1) {
        comando["mudarTap"] = "up";
    }
    else if (tapPos == -1) {
        comando["mudarTap"] = "down";
    }

    //envia comando pela rede
    this->sender->sendDatagram(comando);
}

void SAVC::atualizaTensao(QJsonObject receivedData) {
    qDebug() << "Atualizando Tensao";

    QJsonObject tensaoTPs = receivedData["buses"].toObject();
    for(QJsonObject::iterator it = tensaoTPs.begin(); it != tensaoTPs.end(); it++) {

        //tp1
        if(it.key().endsWith("220kV")) {
            this->tensaoBarra220kv = it.value().toDouble();
        }
        //tp2
        else {
            this->tensaoBarra500kv = it.value().toDouble();
        }
    }

    this->verificaTensao();
}
