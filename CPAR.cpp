#include "CPAR.h"

CPAR::CPAR()
{
}

bool CPAR::verificaTap(){

    switch(grupo){
    case 1:
        if((tapPosR1 == tapPosR2) && (tapPosR1 == tapPosR3)
                && (tapPosR1 == tapPosR4) && (tapPosR1 == tapPosRX)){
            return true;
        }
    case 2:
        if((tapPosR1 == tapPosR2) && (tapPosR1 == tapPosR3)
                && (tapPosR1 == tapPosR4) && (tapPosR1 == tapPosR5)){
            return true;
        }
     case 3:
        if((tapPosR1 == tapPosR2) && (tapPosR1 == tapPosR3)
                && (tapPosR1 == tapPosR5) && (tapPosR1 == tapPosRX)){
            return true;
        }
     case 4:
        if((tapPosR1 == tapPosR2) && (tapPosR1 == tapPosR5)
                && (tapPosR1 == tapPosR4) && (tapPosR1 == tapPosRX)){
            return true;
        }
     case 5:
        if((tapPosR1 == tapPosR5) && (tapPosR1 == tapPosR3)
                && (tapPosR1 == tapPosR4) && (tapPosR1 == tapPosRX)){
            return true;
        }
     case 6:
        if((tapPosR5 == tapPosR2) && (tapPosR5 == tapPosR3)
                && (tapPosR5 == tapPosR4) && (tapPosR5 == tapPosRX)){
            return true;
           }
     default:
        return false;
    }

}


bool CPAR::verificaLoc(){
//true = local e false = remoto
    switch(grupo){
    case 1:
        if((locR1 == locR2) && (locR1 == locR3)
                && (locR1 == locR4) && (locR1 == locRX)){
            return locR1;
        }
    case 2:
        if((locR1 == locR2) && (locR1 == locR3)
                && (locR1 == locR4) && (locR1 == locR5)){
            return locR1;
        }
     case 3:
        if((locR1 == locR2) && (locR1 == locR3)
                && (locR1 == locR5) && (locR1 == locRX)){
            return locR1;
        }
     case 4:
        if((locR1 == locR2) && (locR1 == locR5)
                && (locR1 == locR4) && (locR1 == locRX)){
            return locR1;
        }
     case 5:
        if((locR1 == locR5) && (locR1 == locR3)
                && (locR1 == locR4) && (locR1 == locRX)){
            return locR1;
        }
     case 6:
        if((locR5 == locR2) && (locR5 == locR3)
                && (locR5 == locR4) && (locR5 == locRX)){
            return locR5;
           }
     default:
        return true;
        //retorna true pois se for local o controle é indefinido, e o estado dos YLTC é individual
    }



}


bool CPAR::verificaControleConjunto(){
//retorna 0 = master, 1 = slave, 2 = individual
    switch(grupo){
    case 1:
        if(modR1 == 0){ //master
            if(modR2 != 2){
                if (((modR2 == modR3) && (modR2 == modR4) && (modR2 == modRX) ) != modR1){ //slaves

                    return true;
                }
            }
        }
        if(modR2 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modRX) ) != modR2){ //slaves

                    return true;
                }
            }
        }
        if(modR3 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR2) && (modR1 == modR4) && (modR1 == modRX) ) != modR3){ //slaves

                    return true;
                }
            }
        }
        if(modR4 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR2) && (modR1 == modRX) ) != modR4){ //slaves

                    return true;
                }
            }
        }
        if(modRX == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modR2) ) != modRX){ //slaves

                    return true;
                }
            }
        }

    case 2:
        if(modR1 == 0){ //master
            if(modR2 != 2){
                if (((modR2 == modR3) && (modR2 == modR4) && (modR2 == modR5) ) != modR1){ //slaves

                    return true;
                }
            }
        }
        if(modR2 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modR5) ) != modR2){ //slaves

                    return true;
                }
            }
        }
        if(modR3 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR2) && (modR1 == modR4) && (modR1 == modR5) ) != modR3){ //slaves

                    return true;
                }
            }
        }
        if(modR4 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR2) && (modR1 == modR5) ) != modR4){ //slaves

                    return true;
                }
            }
        }
        if(modR5 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modR2) ) != modR5){ //slaves

                    return true;
                }
            }
        }
     case 3:
        if(modR1 == 0){ //master
            if(modR2 != 2){
                if (((modR2 == modR3) && (modR2 == modR5) && (modR2 == modRX) ) != modR1){ //slaves

                    return true;
                }
            }
        }
        if(modR2 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR5) && (modR1 == modRX) ) != modR2){ //slaves

                    return true;
                }
            }
        }
        if(modR3 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR2) && (modR1 == modR5) && (modR1 == modRX) ) != modR3){ //slaves

                    return true;
                }
            }
        }
        if(modR5 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR2) && (modR1 == modRX) ) != modR5){ //slaves

                    return true;
                }
            }
        }
        if(modRX == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR5) && (modR1 == modR2) ) != modRX){ //slaves

                    return true;
                }
            }
        }
     case 4:
        if(modR1 == 0){ //master
            if(modR2 != 2){
                if (((modR2 == modR5) && (modR2 == modR4) && (modR2 == modRX) ) != modR1){ //slaves

                    return true;
                }
            }
        }
        if(modR2 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR5) && (modR1 == modR4) && (modR1 == modRX) ) != modR2){ //slaves

                    return true;
                }
            }
        }
        if(modR5 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR2) && (modR1 == modR4) && (modR1 == modRX) ) != modR5){ //slaves

                    return true;
                }
            }
        }
        if(modR4 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR5) && (modR1 == modR2) && (modR1 == modRX) ) != modR4){ //slaves

                    return true;
                }
            }
        }
        if(modRX == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR5) && (modR1 == modR4) && (modR1 == modR2) ) != modRX){ //slaves

                    return true;
                }
            }
        }
     case 5:
        if(modR1 == 0){ //master
            if(modR5 != 2){
                if (((modR5 == modR3) && (modR5 == modR4) && (modR5 == modRX) ) != modR1){ //slaves

                    return true;
                }
            }
        }
        if(modR5 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modRX) ) != modR5){ //slaves

                    return true;
                }
            }
        }
        if(modR3 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR5) && (modR1 == modR4) && (modR1 == modRX) ) != modR3){ //slaves

                    return true;
                }
            }
        }
        if(modR4 == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR5) && (modR1 == modRX) ) != modR4){ //slaves

                    return true;
                }
            }
        }
        if(modRX == 0){ //master
            if(modR1 != 2){
                if (((modR1 == modR3) && (modR1 == modR4) && (modR1 == modR5) ) != modRX){ //slaves

                    return true;
                }
            }
        }
     case 6:
        if(modR5 == 0){ //master
            if(modR2 != 2){
                if (((modR2 == modR3) && (modR2 == modR4) && (modR2 == modRX) ) != modR5){ //slaves

                    return true;
                }
            }
        }
        if(modR2 == 0){ //master
            if(modR5 != 2){
                if (((modR5 == modR3) && (modR5 == modR4) && (modR5 == modRX) ) != modR2){ //slaves

                    return true;
                }
            }
        }
        if(modR3 == 0){ //master
            if(modR5 != 2){
                if (((modR5 == modR2) && (modR5 == modR4) && (modR5 == modRX) ) != modR3){ //slaves

                    return true;
                }
            }
        }
        if(modR4 == 0){ //master
            if(modR5 != 2){
                if (((modR5 == modR3) && (modR5 == modR2) && (modR5 == modRX) ) != modR4){ //slaves

                    return true;
                }
            }
        }
        if(modRX == 0){ //master
            if(modR5 != 2){
                if (((modR5 == modR3) && (modR5 == modR4) && (modR5 == modR2) ) != modRX){ //slaves

                    return true;
                }
            }
        }
     default:
        return false;

    }



}


bool CPAR::verificaControleIndividual(){

    switch(grupo){
    case 1:
        if(modR1 ==2){
            if((modR1 == modR2) && (modR1 == modR3)
                   && (modR1 == modR4) && (modR1 == modRX)){
               return true;
         }
        }
    case 2:
        if(modR1 ==2){
            if((modR1 == modR2) && (modR1 == modR3)
                    && (modR1 == modR4) && (modR1 == modR5)){
            return true;
            }
        }
     case 3:
        if(modR1 ==2){
            if((modR1 == modR2) && (modR1 == modR3)
                    && (modR1 == modR5) && (modR1 == modRX)){
            return true;
            }
        }
     case 4:
        if(modR1 ==2){
            if((modR1 == modR2) && (modR1 == modR5)
                    && (modR1 == modR4) && (modR1 == modRX)){
            return true;
            }
        }
     case 5:
        if(modR1 ==2){
            if((modR1 == modR5) && (modR1 == modR3)
                    && (modR1 == modR4) && (modR1 == modRX)){
            return true;
            }
        }
     case 6:
        if(modR5 ==2){
            if((modR5 == modR2) && (modR5 == modR3)
                    && (modR5 == modR4) && (modR5 == modRX)){
            return true;
            }
        }
     default:
        return false; //retorna falso pois não está no modo de operação SINGLE
    }

}

bool CPAR::verificaOltcMovimento(){

    if((mvmR1 == true)|(mvmR2 == true)|(mvmR3 == true)|
            (mvmR4 == true)|(mvmRX == true)|(mvmR5 == true)){
        return true;
    }

    else {
        return false; // se qualquer um dos OLTCs estiver em movimento, retorna true, caso contrário false
    }
}

bool CPAR::verificaOpIncompleta(){

    if((cycAlmR1 == true)|(cycAlmR2 == true)|(cycAlmR3 == true)|
            (cycAlmR4 == true)|(cycAlmRX == true)|(cycAlmR5 == true)){
        return true;
    }

    else {
        return false; // se qualquer um dos OLTCs emitir um alarme de operação incompleta, retorna true, caso contrário false
    }

}

bool CPAR::verificaControleParalelismo(){

    if((this->verificaControleConjunto())&&(!this->verificaLoc())&&(this->verificaTap())){
        return true;
    }
    else {
        if((this->verificaControleIndividual())|(!this->verificaControleConjunto())|(this->verificaOpIncompleta()) ){
            return false; //não entra no controle automático de TAP
        }
    }
}
