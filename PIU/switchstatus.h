#ifndef SWITCHSTATUS_H
#define SWITCHSTATUS_H

#include <cassert>

class SwitchStatus
{


public:



    typedef enum
    {
        /**
         * fechado.
         */
        onOrTrue,
        /**
         * aberto.
         */
        offOrFalse,
        /**
         * em movimento.
         */
        intermediateState,
        /**
         * indefinido
         */
        badState
    } enum_type;

    SwitchStatus( enum_type val = offOrFalse )
        : val( val )
    {
        assert( val <= onOrTrue );
    }

    operator enum_type() const
    {
        return val;
    }

private:
        enum_type val;



};

#endif // SWITCHSTATUS_H
