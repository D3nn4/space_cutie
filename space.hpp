#ifndef _SPACE_H_
#define _SPACE_H_

#include "factory.hpp"
#include "ressources.hpp"

class Space
{
public:
    Space(IFactory* ptrFactory);
    void goToNextResource();
    void goToNextBase();
    Location getCurrent();
    Location getPrevious();

private:
    Location _previous;
    Location _current;
    IFactory* _factory = nullptr;
};

#endif
