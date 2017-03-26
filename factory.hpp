#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <map>
#include <vector>
#include "ressources.hpp"
#include <ctime>
#include <cstdlib>

class Randominterface 
{
public:
    virtual int generate(int, int) = 0;
};

class RandomInt : public Randominterface
{
public:
    RandomInt()
    {
        std::srand(std::time(nullptr));
    }
    int generate(int min, int max)
    {
        int randomQt = (std::rand() % (max - min) + min);
        return randomQt;
    }
};

// class factory

class Factory
{
public:

    Factory(Randominterface* randomGenerator);
    Resource createGivenResource(int totalNeeded, Resource::Type typeNeeded);
    Resource createRandomResource();

private:

    enum class Category
        {
            RAW,
            SHIP
        };

    Resource::Type getRandomLoot() const;

    Randominterface* _randomIntGenerator;
    std::vector<Factory::Category> _categoryResource;
    typedef std::vector<Resource::Type> ResourceTypes;
    typedef std::map< Factory::Category, ResourceTypes> ResourcesPerCategory;
    ResourcesPerCategory _resourceByCategory;
};

#endif
