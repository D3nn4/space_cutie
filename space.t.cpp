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

// TEST_F(SpaceTest, GoToNextResouceCurrentCreated)
// {
//     Resource toReturn;
//     toReturn.type = Resource::Type::SILVER;
//     toReturn.quantity = 200;
//     EXPECT_CALL(factory, createLocation(Location::Type::RESOURCES_SEARCH))
//         .Times(1);
//     EXPECT_CALL(factory, createRandomResource())
//         .Times(3)
//         .WillRepeatedly(Return (toReturn));
//     space.goToNextResource();
//     std::vector<Resource> currentList = space.getCurrent()._listResources;
//     // for(int i = 0; i < 3; ++i){
//     //     Resource current = currentList[i];
//     //     EXPECT_TRUE(current == toReturn);
//     // }
// }

// TEST_F(SpaceTest, GoToNextResouceCurrentBecomePrevious)
// {
//     Resource toReturn1{Resource::Type::IRON, 200};
//     Resource toReturn2{Resource::Type::GOLD, 800};
//     EXPECT_CALL(factory, createRandomResource())
//         .Times(2)
//         .WillOnce(Return (toReturn1))
//         .WillOnce(Return (toReturn2));
//     space.goToNextResource();
//     space.goToNextResource();
//     Resource current = space.getCurrent();
//     EXPECT_TRUE(current == toReturn2);
//     Resource previous = space.getPrevious();
//     EXPECT_TRUE(previous == toReturn1);
// }
