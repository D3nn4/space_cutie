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
    std::vector<uint> myList = {9, 0, 3};
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
    EXPECT_THAT(resource.quantity, Eq(900));
    EXPECT_THAT(resource.type, Eq(Resource::Type::SILVER));
}


// TEST_F(FactoryTest, RandomClassReturnRandomIntBetweenTwonegativeRange)
// {
//   const int min = -40;
//   const int max = -99;
//   uint result = randomInt.generate(min,max);
//   EXPECT_THAT(result, Ge(min)) ;
//   EXPECT_THAT(result, Le(max));
// }

