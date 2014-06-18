#ifndef SAVC_H
#define SAVC_H

#include <LD.h>
#include <ATCC.h>
#include <MMXU.h>

class SAVC: public LD
{
private:
    ATCC *speATCC;
    MMXU *mmxu1;
    MMXU *mmxu2;

public:
    SAVC();
    ~SAVC();
};

#endif // SAVC_H
