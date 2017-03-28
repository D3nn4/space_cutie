#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <map>
#include <vector>
#include "ressources.hpp"
#include <ctime>
#include <cstdlib>
#include <cstdint>

class IRandom
{
public:
    virtual uint generate(uint, uint) = 0;
};

class RandomInt : public IRandom
{
public:
    RandomInt()
    {
        std::srand(std::time(nullptr));
    }
    uint generate(uint min, uint max)
    {
        uint randomQt = (std::rand() % (max - min) + min);
        return randomQt;
    }
};
// factory interface

class IFactory
{
public:
    virtual Resource createGivenResource(uint totalNeeded, Resource::Type typeNeeded) = 0;
    virtual Resource createRandomResource() = 0;
    virtual ~IFactory(){};
};
// class factory

class Factory : public IFactory
{
public:

    Factory(IRandom* randomGenerator);
    Resource createGivenResource(uint totalNeeded, Resource::Type typeNeeded);
    Resource createRandomResource();
    ~Factory(){};

private:

    enum class Category
        {
            RAW,
            SHIP
        };

    typedef std::vector<Resource::Type> ResourceTypes;
    typedef std::map< Factory::Category, ResourceTypes> ResourcesPerCategory;

    Resource::Type getRandomLoot() const;

    IRandom* _randomIntGenerator;
    std::vector<Factory::Category> _categoryResource;
    ResourcesPerCategory _resourceByCategory;
};

#endif
