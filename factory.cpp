#include <stdlib.h>
#include <time.h>
#include <cstdint>
#include "factory.hpp"


Factory::Factory(IRandom* randomGenerator)
    :_randomIntGenerator(randomGenerator)
{
    _categoryResource.push_back(Factory::Category::RAW);
    _categoryResource.push_back(Factory::Category::SHIP);
    ResourceTypes rawRessource = {
        Resource::Type::GOLD,
        Resource::Type::COPPER,
        Resource::Type::IRON,
        Resource::Type::SILVER
    };
    ResourceTypes shipRessource = {
        Resource::Type::FUEL_TANK,
        Resource::Type::CARGO_POD
    };
    _resourceByCategory[Factory::Category::RAW]= rawRessource;
    _resourceByCategory[Factory::Category::SHIP]= shipRessource;
}

Resource Factory::createGivenResource(uint totalNeeded, Resource::Type typeNeeded)
{
    Resource resource;
    resource.type = typeNeeded;
    resource.quantity = totalNeeded;
    return resource;
}

Resource Factory::createRandomResource()
{
    Resource randomResource;
    randomResource.quantity = _randomIntGenerator->generate(1, 9) * 100;
    randomResource.type = getRandomLoot();
    return randomResource;
}


Resource::Type Factory::getRandomLoot() const
{
    uint totalCategory = _resourceByCategory.size() - 1;
    uint randomCategoryResource = _randomIntGenerator->generate(0, totalCategory);
    Factory::Category choosenCategory = _categoryResource[randomCategoryResource];
    auto choosenTypeIt = _resourceByCategory.find(choosenCategory);
    uint randomLoot = 0;
    if(choosenTypeIt != _resourceByCategory.end()){
        randomLoot = _randomIntGenerator->generate(0, (choosenTypeIt->second.size()- 1));
    }
    // handle case choosenTypeIt == .end()
    return choosenTypeIt->second[randomLoot];
}
