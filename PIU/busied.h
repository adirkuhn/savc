#ifndef BUSIED_H
#define BUSIED_H

#include "LD.h"
#include "TVTR.h"
#include <QString>
#include <P_VISIBLE_STRING32.h>
class BusIED: public LD
{
private:
    TVTR *TVTR2;
    int vol;

public:
    BusIED();

    void setLDName(QString name);
    QString getLDName();
    void setVol(int vol);
    int getVol();

};

#endif // BUSIED_H
