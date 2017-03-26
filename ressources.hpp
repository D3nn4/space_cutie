
#ifndef _RESSOURCES_H_
#define _RESSOURCES_H_

#include <string>

struct Resource
{
    enum class Type
    {
        RAW_MATERIAL,
        SHIP_PART
    };

    Type type;
    int quantity = 0;
};

#endif
