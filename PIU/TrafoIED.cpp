#include "TrafoIED.h"

/**
 * TODO:
 * atributos nao localizados
 * LTCMvm - pertence ao CEPAR
 * LTCMod - pertence ao ATCC
 * LTCCycAlm - implementado
 * Loc -implementado
 */

TrafoIED::TrafoIED()
{
    this->YLTC1 = new YLTC();

}

void TrafoIED::setLDName(QString name) {
    P_VISIBLE_STRING32 tmpName;
    tmpName.setValue(name);

    this->setName(tmpName);
}

QString TrafoIED::getLDName() {
    return this->getName().getObjectName().getValue();
}

void TrafoIED::setPos(int pos) {

    //Verificar se o a pos esta dentro dos limites
    //se for menor ou igual a 0
    this->setEndPosL(false);
    this->setEndPosR(false);
    if (pos < 1) {
        pos = 0;
        this->setEndPosL(true);
        this->setEndPosR(false);
    }
    //se for maior ou igual a 18
    if (pos > 17) {
        pos = 18;
        this->setEndPosL(false);
        this->setEndPosR(true);
    }

    INT8 ctlVal;
    ctlVal.val.val = pos;

    //deve setar o valor em ctlVal
    this->YLTC1->TapPos.ctlVal.setAttr(ctlVal);

    //Deve iniciar a mudança de TAP

    qDebug() << "TODO: Iniciar a mudança do TAP";

    //depois de mudar o valor o resultado deve ser colocado em YLTC.TapChg.valWithTrans.posVal
    //mas nao existe esse propriedade
    ValWithTrans valWTransPosition;
    valWTransPosition.posVal.val.val = pos;
    this->YLTC1->TapPos.valWTr.setAttr(valWTransPosition);
}

int TrafoIED::getPos() {

    return this->YLTC1->TapPos.valWTr.getAttr().posVal.val.val;
}

void TrafoIED::setEndPosL(bool endPosL) {
    P_BOOLEAN reachedLowerPositon;
    BOOLEAN boolean;
    BOOLEAN_ST_dchg boolean_st_dchg;

    reachedLowerPositon.setVal(endPosL);
    boolean.setVal(reachedLowerPositon);
    boolean_st_dchg.setAttr(boolean);


    this->YLTC1->EndPosL.stVal = boolean_st_dchg;
}

bool TrafoIED::getEndPosL() {

    return this->YLTC1->EndPosL.stVal.getAttr().getVal().getVal();
}

void TrafoIED::setEndPosR(bool endPosR) {
    P_BOOLEAN reachedRaisePositon;
    BOOLEAN boolean;
    BOOLEAN_ST_dchg boolean_st_dchg;

    reachedRaisePositon.setVal(endPosR);
    boolean.setVal(reachedRaisePositon);
    boolean_st_dchg.setAttr(boolean);


    this->YLTC1->EndPosR.stVal = boolean_st_dchg;
}

bool TrafoIED::getEndPosR() {

    return this->YLTC1->EndPosR.stVal.getAttr().getVal().getVal();
}

int TrafoIED::getTapChg(){

    return this->YLTC1->TapChg.valWTr.getAttr().posVal.val.val;
}

void TrafoIED::setTapChg(int val){
    P_INT8 valFinal;
    //INT8 posVal;
    ValWithTrans valWtr;

    valFinal.val = val;
    valWtr.posVal.setVal(valFinal);

    this->YLTC1->TapChg.valWTr.setAttr(valWtr);
    //verificar se o valor deve ser passado no ctVal ou no valWtr

}

bool TrafoIED::getLoc(){

    return this->getLLn0()->Loc.stVal.getAttr().getVal().getVal();
    //retorna o valor "modo de operacao" se é local ou remoto

}

void TrafoIED::setLoc(bool loc){
    P_BOOLEAN val;
    BOOLEAN attr;
    BOOLEAN_ST_dchg stVal;

    val.setVal(loc);
    attr.setVal(val);
    stVal.setAttr(attr);

    this->getLLn0()->Loc.stVal = stVal;

}

bool TrafoIED::getLTCCycAlm(){
    return this->YLTC1->LTCCycAlm.stVal.getAttr().getVal().getVal();
    //retorna o alarme se o ciclo de mudança foi incompleto
}

void TrafoIED::setLTCCycAlm(bool alm){
    P_BOOLEAN val;
    BOOLEAN attr;
    BOOLEAN_ST_dchg stVal;

    val.setVal(alm);
    attr.setVal(val);
    stVal.setAttr(attr);

    this->YLTC1->LTCCycAlm.stVal = stVal;
}
