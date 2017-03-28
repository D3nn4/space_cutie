#ifndef _SPACE_H_
#define _SPACE_H_

#include "factory.hpp"
#include "ressources.hpp"

class Space
{
public:
    Space(IFactory* ptrFactory);
private:
    IFactory* factory = nullptr;
};

#endif
