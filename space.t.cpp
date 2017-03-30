#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "space.hpp"
#include <iostream>


using namespace testing;
using ::testing::Return;

class MockFactory : public IFactory
{
public:
    MOCK_METHOD0(createRandomResource, Resource());
    MOCK_METHOD2(createGivenResource, Resource(uint, Resource::Type));
    MOCK_METHOD1(createLocation, Location(Location::Type));
};


class SpaceTest  : public testing::Test
{
public:
    SpaceTest()
        :space(&factory){};
    MockFactory factory;
    Space space;
};

TEST_F(SpaceTest, CurrentHasNoNameAndEmptyResourceList)
{
    EXPECT_TRUE(space.getCurrent()._name.empty());
    EXPECT_TRUE(space.getCurrent()._listResources.empty());
}

TEST_F(SpaceTest, GoToNextResouceCurrentCreated)
{
    EXPECT_CALL(factory, createLocation(Location::Type::RESOURCES_SEARCH))
        .Times(1);
    space.goToNextResource();
}

TEST_F(SpaceTest, PreviousBecomeCurrentAfterSecondTravel)
{
    Location firstTravel;
    firstTravel._type = Location::Type::MERCHANT_BASE;
    firstTravel._name = "FirstPlace";
    Location SecondTravel;
    firstTravel._type = Location::Type::RESOURCES_SEARCH;
    firstTravel._name = "SecondPlace";

    EXPECT_CALL(factory, createLocation(Location::Type::RESOURCES_SEARCH))
        .Times(2)
        .WillOnce(Return(firstTravel))
        .WillOnce(Return(SecondTravel));

    space.goToNextResource();
    space.goToNextResource();

    EXPECT_TRUE(space.getPrevious()._type == firstTravel._type);
    EXPECT_TRUE(space.getCurrent()._type == SecondTravel._type);
}
