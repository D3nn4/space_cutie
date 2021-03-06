#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cstdint>

#include "ressources.hpp"
#include "location.hpp"

class IRandom
{
public:
    virtual uint generate(uint, uint) = 0;
    virtual ~IRandom(){};
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
    virtual Location createLocation(Location::Type typeNeeded) = 0;
    virtual Resource createGivenResource(uint totalNeeded, Resource::Type typeNeeded) = 0;
    virtual Resource createRandomResource() = 0;
    virtual ~IFactory(){};
};
// class factory

class Factory : public IFactory
{
public:

    Factory(IRandom* randomGenerator);
    Location createLocation(Location::Type typeNeeded);
    Resource createGivenResource(uint totalNeeded, Resource::Type typeNeeded);
    Resource createRandomResource();

protected:

    enum class ResourceCategory
        {
            RAW
        };
    // enum class ShipCategory
    //     {
    //         ENEMY,
    //         SHIPWRECK
    //     };

    typedef std::vector<Resource::Type> ResourceTypes;
    typedef std::map< Factory::ResourceCategory, ResourceTypes> ResourcesPerCategory;
    // typedef std::map< Factory::ShipCategory, ResourceTypes> ShipPerCategory;

    Resource::Type getRandomLoot() const;
    std::string getBaseName();
    std::string getResourcePlaceName();

    IRandom* _randomIntGenerator;
    std::vector<Factory::ResourceCategory> _categoryResource;
    ResourcesPerCategory _resourceByCategory;
    // std::vector<Factory::ShipCategory> _categoryShip;
    // ShipPerCategory _ShipByCategory;
};

#endif
