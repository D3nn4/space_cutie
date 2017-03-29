#include "space.hpp"


Space::Space(IFactory* ptrFactory)
    :_factory(ptrFactory){};

void Space::goToNextResource()
{
    _previous = _current;
    Resource newResource = _factory->createRandomResource();
    _current = newResource;
}

Resource Space::getCurrent()
{
    return _current;
}

Resource Space::getPrevious()
{
    return _previous;
}
