#include "tests.h"

class memset_class : public ::testing::Test {
protected:
	char lib[STRSIZE];
	char test[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(memset_class, memset)
{
	strcpy(lib, "123456789");
	strcpy(test, "123456789");
	char s = '$';
	memset(lib+2, s, 5);
	ft_memset(test+2, s, 5);
	EXPECT_STREQ(lib, test);
}
