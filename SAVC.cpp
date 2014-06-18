#include "SAVC.h"

SAVC::SAVC()
{
    this->speATCC = new ATCC;
    this->mmxu1 = new MMXU;
    this->mmxu2 = new MMXU;
}

SAVC::~SAVC() {
    delete this->speATCC;
    delete this->mmxu1;
    delete this->mmxu2;
}
