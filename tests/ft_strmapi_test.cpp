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

TEST_F(strmapi_class, error)
{
	EXPECT_EQ(NULL, ft_strmapi("abcde", NULL));
	EXPECT_EQ(NULL, ft_strmapi(NULL, &strmapi_func));
}