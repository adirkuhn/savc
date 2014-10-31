#ifndef BREAKERIED_H
#define BREAKERIED_H

#include "LD.h"
#include "XCBR.h"
#include <QString>
#include <P_VISIBLE_STRING32.h>
#include "PIU/BreakerStatus.h"
#include <DPStatusKind.h>

#include <GooseMessage.h>
#include <QDebug>

class BreakerIED: public LD
{
private:
    XCBR *XCBR1;
    XCBR *XCBR2;
    XCBR *XCBR3;

    GooseMessage *gooseMessage;
    GooseMessage *gooseMessage2;
    GooseMessage *gooseMessage3;

public:
    BreakerIED();

    void setLDName(QString name);
    QString getLDName();
    void setPos(int pos);
    int getPos();
    void exec();

    void setMacAddress(int mac);
    void sendGoose();

};

#endif // BREAKERIED_H
