#ifndef SWITCHIED_H
#define SWITCHIED_H

#include "LD.h"
#include "XSWI.h"
#include <QString>
#include <P_VISIBLE_STRING32.h>
#include <DPStatusKind.h>
#include <GooseMessage.h>
#include <qdebug.h>

class SwitchIED: public LD
{

private:
    XSWI *XSWI1;

    GooseMessage *gooseMessage;

public:
    SwitchIED();

    void setLDName(QString name);
    QString getLDName();
    void setPos(int pos);
    int getPos();
    void exec();

    void setMacAddress(int mac);
    void sendGoose();
};

#endif // SWITCHIED_H
