#ifndef _LOCATION_H_
#define _LOCATION_H_

#include "ressources.hpp"
#include <string>
#include <vector>
#include <cstdbool>

struct Location
{
    enum class Type {
        EMPTY,
        MERCHANT_BASE,
        RESOURCES_SEARCH

    };

    Location::Type _type = Location::Type::EMPTY;
    std::string _name;
    uint _maxResourceType = 3;
    std::vector<Resource> _listResources;

    // bool isRefuelAvailable();
};

#endif
