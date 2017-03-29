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
};


class SpaceTest  : public testing::Test
{
public:
    SpaceTest()
        :space(&factory){};
    MockFactory factory;
    Space space;
};

TEST_F(SpaceTest, GoToNextResouceCurrentCreated)
{
    Resource toReturn{Resource::Type::SILVER, 200};
    EXPECT_CALL(factory, createRandomResource())
        .Times(1)
        .WillOnce(Return (toReturn));
    space.goToNextResource();
    Resource current = space.getCurrent();
    EXPECT_TRUE(current == toReturn);
}

TEST_F(SpaceTest, GoToNextResouceCurrentBecomePrevious)
{
    Resource toReturn1{Resource::Type::IRON, 200};
    Resource toReturn2{Resource::Type::GOLD, 800};
    EXPECT_CALL(factory, createRandomResource())
        .Times(2)
        .WillOnce(Return (toReturn1))
        .WillOnce(Return (toReturn2));
    space.goToNextResource();
    space.goToNextResource();
    Resource current = space.getCurrent();
    EXPECT_TRUE(current == toReturn2);
    Resource previous = space.getPrevious();
    EXPECT_TRUE(previous == toReturn1);
}
