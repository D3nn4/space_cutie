#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ship.hpp"

using namespace testing;
class ShipTest  : public Test
{
public:
    Ship ship;
};

TEST_F(ShipTest, TestThatFuelNeededToTravelIsSubToCurrentFuel)
{
    uint fuelNeeded = 50;
    ship.travel(fuelNeeded);
    EXPECT_THAT(ship.getCurrentFuel(), Eq(ship.getMaxFuel() - fuelNeeded));
}
