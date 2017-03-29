
#ifndef _RESSOURCES_H_
#define _RESSOURCES_H_

#include <string>
#include <cstdbool>
struct Resource
{
    enum class Type
    {
        EMPTY,
        GOLD,
        COPPER,
        IRON,
        SILVER,
        FUEL_TANK,
        CARGO_POD
    };

    bool operator==(Resource rhs){
        if (type == rhs.type
            && quantity == rhs.quantity)
            return true;
        return false;
    };
    Type type;
    int quantity;
};

#endif
