#include <stdlib.h>
#include <time.h>
#include <cstdint>
#include "factory.hpp"


Factory::Factory(IRandom* randomGenerator)
    :_randomIntGenerator(randomGenerator)
{
    //RESSOURCES
    _categoryResource.push_back(Factory::ResourceCategory::RAW);
    ResourceTypes rawRessource = {
        Resource::Type::GOLD,
        Resource::Type::COPPER,
        Resource::Type::IRON,
        Resource::Type::SILVER
    };
    _resourceByCategory[Factory::ResourceCategory::RAW]= rawRessource;
    //SHIP
    // _categoryShip.push_back(Factory::ShipCategory::SHIPWRECK);
    // ResourceTypes shipRessource = {
    //     Resource::Type::FUEL_TANK,
    //     Resource::Type::CARGO_POD
    // };
    // _ShipByCategory[Factory::ShipCategory::SHIPWRECK]= shipRessource;
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
    Factory::ResourceCategory choosenCategory = _categoryResource[randomCategoryResource];
    auto choosenTypeIt = _resourceByCategory.find(choosenCategory);
    uint randomLoot = 0;
    if(choosenTypeIt != _resourceByCategory.end()){
        randomLoot = _randomIntGenerator->generate(0, (choosenTypeIt->second.size()- 1));
    }
    if(choosenTypeIt == _resourceByCategory.end()){
        return Resource::Type::EMPTY;
    }
    return choosenTypeIt->second[randomLoot];
}

std::string Factory::getBaseName()
{
    std::string name("Spaceport ");
    int letterA = 65;
    int letterZ = 90;
    name += _randomIntGenerator->generate(letterA, letterZ);
    name += "-";
    for(int i = 0; i < 3; ++i){
        name += std::to_string(_randomIntGenerator->generate(0, 9));
    }
    return name;
    return name;
};

std::string Factory::getResourcePlaceName()
{
    std::string name("Stellar object ");
    int letterA = 65;
    int letterZ = 90;
    name += _randomIntGenerator->generate(letterA, letterZ);
    name += "-";
    for(int i = 0; i < 3; ++i){
        name += std::to_string(_randomIntGenerator->generate(0, 9));
    }
    return name;
};

Location Factory::createLocation(Location::Type typeNeeded)
{
    Location newLocation;
    newLocation._type = typeNeeded;
    if(typeNeeded == Location::Type::MERCHANT_BASE){
        newLocation._name = getBaseName();
    }
    else if(typeNeeded == Location::Type::RESOURCES_SEARCH){
        newLocation._name = getResourcePlaceName();
    }
    for(uint i = 0; i < newLocation._maxResourceType; ++i){
        newLocation._listResources.push_back(createRandomResource());
    }
    return newLocation;

}
