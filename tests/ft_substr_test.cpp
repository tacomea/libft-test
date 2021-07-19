#include "tests.h"

class substr_class : public ::testing::Test {
protected:

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(substr_class, substr)
{
	// EXPECT_STREQ("", ft_substr(NULL, 1, 1));
	EXPECT_STREQ("", ft_substr("Lorem ipsum dolor sit amet,", 2, 0));
	EXPECT_STREQ("", ft_substr("Lorem ipsum dolor sit amet,", 50, 0));
	EXPECT_STREQ("rem i", ft_substr("Lorem ipsum dolor sit amet,", 2, 5));
	EXPECT_STREQ("or sit amet,", ft_substr("Lorem ipsum dolor sit amet,", 15, 20));
}