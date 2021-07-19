#include "tests.h"

class strtrim_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(strtrim_class, strtrim)
{
	EXPECT_EQ(NULL, ft_strtrim(NULL, "42tokyo"));
	EXPECT_EQ(NULL, ft_strtrim("42tokyo", NULL));
	EXPECT_EQ(NULL, ft_strtrim(NULL, NULL));
	EXPECT_STREQ("42tokyo", ft_strtrim("abc42tokyoabc", "abc"));
	EXPECT_STREQ("abc Cursus ABC", ft_strtrim("    abc Cursus ABC   ", " "));
}