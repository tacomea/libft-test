#include "tests.h"

class strmapi_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

char	strmapi_func(unsigned int n, char c)
{
	c = c + n;
	return (c);
}

TEST_F(strmapi_class, strmapi)
{
	EXPECT_STREQ("acegi", ft_strmapi("abcde", &strmapi_func));
}