#include <gmock/gmock.h>

class common_test: public testing::Test
{
public:
};

TEST_F(common_test, CheckSomeResults)
{
    EXPECT_EQ((unsigned int) 10, 5 * 2);
}

