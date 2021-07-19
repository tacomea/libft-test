#include "tests.h"

class split_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(split_class, split)
{
	split = ft_split("aaa42aatokyoaaa", 'a');
	EXPECT_STREQ("42", split[0]);
	EXPECT_STREQ("tokyo", split[1]);
	split = ft_split(NULL, 'a');
	EXPECT_EQ(NULL, split);
}
