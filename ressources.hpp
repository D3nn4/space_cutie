
#ifndef _RESSOURCES_H_
#define _RESSOURCES_H_

#include <string>

struct Resource
{
    enum class Type
    {
        GOLD,
        COPPER,
        IRON,
        SILVER,
        FUEL_TANK,
        CARGO_POD
    };

    Type type;
    int quantity = 0;
};

#endif
