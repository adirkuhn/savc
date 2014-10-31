#ifndef BREAKERSTATUS_H
#define BREAKERSTATUS_H

#include <cassert>

class BreakerStatus
{
public:
/**
 * 4-way.
 */
typedef enum
{
    /**
     * Aberto.
     */
    open,
    /**
     * Semi-aberto.
     */
    half_open,
    /**
     * Fechado.
     */
    closed
} enum_type;

private:
    enum_type val;

public:
    BreakerStatus( enum_type val = open )
        : val( val )
    {
        assert( val <= closed );
    }

    operator enum_type() const
    {
        return val;
    }
};
#endif // BREAKERSTATUS_H
