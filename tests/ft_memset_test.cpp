#include "tests.h"

class memset_class : public ::testing::Test {
protected:
	char lib[STRSIZE];
	char test[STRSIZE];

	virtual void SetUp(){
		strcpy(lib, "0123456789");
        strcpy(test, "0123456789");
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
