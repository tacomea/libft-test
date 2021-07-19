#include "tests.h"

class memset_class : public ::testing::Test {
protected:

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(memset_class, memset)
{
	char s = '$';
	memset(lib+2, s, 5);
	ft_memset(test+2, s, 5);
	EXPECT_STREQ(lib, test);
}
