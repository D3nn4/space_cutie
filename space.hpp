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
    Resource getCurrent();
    Resource getPrevious();

private:
    Resource _previous;
    Resource _current;
    IFactory* _factory = nullptr;
};

#endif
