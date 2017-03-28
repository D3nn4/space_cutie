#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "space.hpp"


using namespace testing;

class MockFactory : public IFactory
{
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


