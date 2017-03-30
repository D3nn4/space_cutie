#include "ship.hpp"

bool Ship::travel(uint fuelNeeded )
{
    if (_currentFuel < fuelNeeded){
        return false;
    }
    _currentFuel -= fuelNeeded;
    return true;
}

uint Ship::getMaxFuel()
{
    return _maxFuel;
}

uint Ship::getCurrentFuel()
{
    return _currentFuel;
}
