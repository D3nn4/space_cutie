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
