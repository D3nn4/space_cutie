#include <stdlib.h>
#include <time.h>
#include "factory.hpp"


Factory::Factory(Randominterface* randomGenerator)
    :_randomIntGenerator(randomGenerator)
{
    _categoryResource.push_back(Factory::Category::RAW);
    _categoryResource.push_back(Factory::Category::SHIP);
    ResourceTypes rawRessource = {
            Resource::Type::RAW_MATERIAL
    };
    ResourceTypes shipRessource = {
            Resource::Type::SHIP_PART
    };
    _resourceByCategory[Factory::Category::RAW]= rawRessource;
    _resourceByCategory[Factory::Category::SHIP]= shipRessource;
}

Resource Factory::createGivenResource(int totalNeeded, Resource::Type typeNeeded)
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
    int totalCategory = _resourceByCategory.size() - 1;
    int randomCategoryResource = _randomIntGenerator->generate(0, totalCategory);
    Factory::Category choosenCategory = _categoryResource[randomCategoryResource];
    auto choosenTypeIt = _resourceByCategory.find(choosenCategory);
    int randomLoot = 0;
    if(choosenTypeIt != _resourceByCategory.end()){
        randomLoot = _randomIntGenerator->generate(0, (choosenTypeIt->second.size()- 1));
    }
    // handle case choosenTypeIt == .end()
    return choosenTypeIt->second[randomLoot];
}
