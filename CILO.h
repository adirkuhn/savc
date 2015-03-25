#ifndef CILO_H
#define CILO_H

#include <QMap>
#include "PIU/BreakerIED.h"

class CILO
{
public:
    QMap<QString, BreakerIED*> *breakers;
    CILO();
};

#endif // CILO_H
