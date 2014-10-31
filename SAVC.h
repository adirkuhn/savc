#ifndef SAVC_H
#define SAVC_H

#include <QDebug>

#include <QObject>
#include <QJsonObject>
#include <LD.h>
#include <ATCC.h>
#include <MMXU.h>
#include <CILO.h>
#include <Multicast/Sender.h>

class SAVC: public QObject, public LD
{
Q_OBJECT
private:
    //PARAMS
    static const float bandaMorta;
    static const float tensaoBaixaAceitavel;
    static const float tensaoAltaAceitavel;

    //TODO: Variaveis apenas para testes, os valores devem ser recebidos por SMV e calculados no MMXU,
    float tensaoBarra220kv;
    float tensaoBarra500kv;

    //LN
    ATCC *speATCC;
    MMXU *mmxu1;
    MMXU *mmxu2;
    CILO *cilo;

    //Networkd
    Sender *sender;


    void verificaTensao();
    void mudaTap(short int tapPos);

public:
    SAVC();
    ~SAVC();


public slots:
    void atualizaTensao(QJsonObject receivedData);

};

#endif // SAVC_H
