#include "busied.h"

BusIED::BusIED()
{
    this->TVTR2 = new TVTR();

}

void BusIED::setLDName(QString name) {
    P_VISIBLE_STRING32 tmpName;
    tmpName.setValue(name);

    this->setName(tmpName);
}

QString BusIED::getLDName(){
   return this->getName().getObjectName().getValue();
}

void BusIED::setVol(int vol){
    this->vol = vol;

    //TODO = o vol é Sampled Value, então criamos e alteramos a variável INT vol
}

int BusIED::getVol() {
    return this->vol;
}

