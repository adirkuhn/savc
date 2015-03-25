#include "CILO.h"

CILO::CILO()
{
    this->breakers = new QMap<QString, BreakerIED*>();
}
