#ifndef CPAR_H
#define CPAR_H

class CPAR
{
public:
    CPAR();
    int *grupo;
    bool verificaTap();
    bool verificaLoc();
    bool verificaControleConjunto();
    bool verificaControleIndividual();
    bool verificaOltcMovimento();
    bool verificaOpIncompleta();
    bool verificaControleParalelismo();

private:
    int tapPosR1;
    bool locR1;
    int modR1;
    bool mvmR1;
    bool cycAlmR1;

    int tapPosR2;
    bool locR2;
    int modR2;
    bool mvmR2;
    bool cycAlmR2;

    int tapPosR3;
    bool locR3;
    int modR3;
    bool mvmR3;
    bool cycAlmR3;

    int tapPosR4;
    bool locR4;
    int modR4;
    bool mvmR4;
    bool cycAlmR4;

    int tapPosR5;
    bool locR5;
    int modR5;
    bool mvmR5;
    bool cycAlmR5;

    int tapPosRX;
    bool locRX;
    int modRX;
    bool mvmRX;
    bool cycAlmRX;
};

#endif // CPAR_H
