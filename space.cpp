#include "space.hpp"


Space::Space(IFactory* ptrFactory)
    :_factory(ptrFactory){};

void Space::goToNextResource()
{
    _previous = _current;
    Location newResource = _factory->createLocation(Location::Type::RESOURCES_SEARCH);
    _current = newResource;
}

void Space::goToNextBase()
{
    _previous = _current;
    Location newResource = _factory->createLocation(Location::Type::MERCHANT_BASE);
    _current = newResource;
}

Location Space::getCurrent()
{
    return _current;
}

Location Space::getPrevious()
{
    return _previous;
}
