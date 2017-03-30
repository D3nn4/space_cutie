#ifndef _SHIP_H_
#define _SHIP_H_

#include <vector>
#include "ressources.hpp"
#include <cstdbool>
class Ship
{
public:
    bool travel(uint fuelNeeded);
    uint getMaxFuel();
    uint getCurrentFuel();

private:
    uint _maxFuel = 200;
    uint _currentFuel = 200;
    uint _maxCargoSpot = 5;
    std::vector<Resource> _cargoList;
};

#endif

