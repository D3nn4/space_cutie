#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "factory.hpp"
#include "ressources.hpp"
#include <iostream>

using namespace testing;

class RandomTest : public Randominterface
{
    int generate(int, int)
    {
        return myList[current++];
    }
    std::vector<int> myList = {9, 1, 0};
    int current = 0;
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
    resource = factory.createGivenResource(100, Resource::Type::RAW_MATERIAL);
    EXPECT_THAT(resource.quantity, Eq(100));
    EXPECT_THAT(resource.type, Eq(Resource::Type::RAW_MATERIAL));
}

TEST_F(FactoryTest, ResourceObjectCreatedWithRandomQt)
{
    resource = factory.createRandomResource();
    EXPECT_THAT(resource.quantity, Ge(0));
    EXPECT_THAT(resource.quantity, Le(900));
}

TEST_F(FactoryTest, RandomClassReturnRandomIntBetweenTwoPositiveRange)
{
    const int min = 40;
    const int max = 99;
    int result = randomInt.generate(min,max);
    EXPECT_THAT(result, Ge(min)) ;
    EXPECT_THAT(result, Le(max));
}

TEST_F(FactoryTest, ResourceObjectCreatedWithRandomType)
{
    resource = factory.createRandomResource();
    EXPECT_THAT(resource.quantity, Eq(900));
    EXPECT_THAT(resource.type, Eq(Resource::Type::SHIP_PART));
}
