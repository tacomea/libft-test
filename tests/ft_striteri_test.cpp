#include "tests.h"

class striteri_class : public ::testing::Test {
protected:
	char test[BUFSIZ];

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};


void	striteri_func(unsigned int i, char *s)
{
	*s = *s + i;
}

TEST_F(striteri_class, striteri)
{
	strcpy(test, "abcde");
	ft_striteri(test, &striteri_func);
	EXPECT_STREQ("acegi", test);
}