#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "factory.hpp"
#include "ressources.hpp"
#include <iostream>

using namespace testing;

class RandomTest : public IRandom
{
    uint generate(uint, uint)
    {
        return myList[current++];
    }
  std::vector<uint> myList = {65, 0, 3, 8, 9, 0, 1, 8, 0, 2, 7, 0, 3};
    uint current = 0;
};

class FactoryTest  : public testing::Test
{
public:
    FactoryTest()
        :factory(&random){};

    RandomTest random;
    RandomInt randomInt;
    Factory factory;
    Resource resource;
};

TEST_F(FactoryTest, ResourceObjectCreatedWithArgs)
{
    resource = factory.createGivenResource(100, Resource::Type::FUEL_TANK);
    EXPECT_THAT(resource.quantity, Eq(100));
    EXPECT_THAT(resource.type, Eq(Resource::Type::FUEL_TANK));
}

TEST_F(FactoryTest, RandomClassReturnRandomIntBetweenTwoPositiveRange)
{
  const int min = 40;
  const int max = 99;
  uint result = randomInt.generate(min,max);
  EXPECT_THAT(result, Ge(min)) ;
  EXPECT_THAT(result, Le(max));
}

TEST_F(FactoryTest, ResourceObjectCreatedWithRandomGenerator)
{
    resource = factory.createRandomResource();
    EXPECT_THAT(resource.type, Eq(Resource::Type::SILVER));
}

TEST_F(FactoryTest, ProperLocationObjectReturnWithCreateLocation)
{
  Location newLocation;
  newLocation = factory.createLocation(Location::Type::RESOURCES_SEARCH);
  Resource expectedResource0;
  expectedResource0.type = Resource::Type::COPPER;
  expectedResource0.quantity = 900;
  Resource expectedResource1;
  expectedResource1.type = Resource::Type::IRON;
  expectedResource1.quantity = 800;
  Resource expectedResource2;
  expectedResource2.type = Resource::Type::SILVER;
  expectedResource2.quantity = 700;
  EXPECT_TRUE(newLocation._listResources[0] == expectedResource0);
  EXPECT_TRUE(newLocation._listResources[1] == expectedResource1);
  EXPECT_TRUE(newLocation._listResources[2] == expectedResource2);
}

