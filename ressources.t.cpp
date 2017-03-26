
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "ressources.hpp"

using namespace testing;

class ResourceEncoding : public testing::Test
{
public:
    Resource resource;
};

TEST_F(ResourceEncoding, MemberVarCreatedAndFilled)
{
    resource.type = Resource::Type::RAW_MATERIAL;
    ASSERT_THAT(resource.quantity, Eq(0) );
    ASSERT_THAT(resource.type, Eq(Resource::Type::RAW_MATERIAL));
}


