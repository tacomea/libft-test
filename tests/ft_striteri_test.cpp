#include "tests.h"

void	striteri_func(unsigned int i, char *s)
{
	*s = *s + i;
}

TEST_F(LibftTestPart2, striteri)
{
	strcpy(test, "abcde");
	ft_striteri(test, &striteri_func);
	EXPECT_STREQ("acegi", test);
}