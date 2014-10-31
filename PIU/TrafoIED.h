#ifndef TRAFOIED_H
#define TRAFOIED_H

#include <LD.h>
#include <YLTC.h>
#include <SPS.h>

#include <QDebug>

class TrafoIED: public LD
{
private:
    YLTC *YLTC1;
    //LD *loc;

public:
    TrafoIED();


    void setLDName(QString name);
    QString getLDName();
    void setPos(int pos);
    int getPos();

    void setEndPosL(bool endPosL);
    bool getEndPosL();

    void setEndPosR(bool endPosR);
    bool getEndPosR();

    int getTapChg();
    void setTapChg (int val);

    bool getLoc();
    void setLoc(bool loc);

    bool getLTCCycAlm();
    void setLTCCycAlm(bool alm);


};

#endif // TRAFOIED_H
