#include "tests.h"

class itoa_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(itoa_class, itoa) {
	EXPECT_EQ(0, strcmp(ft_itoa(-123), "-123"));
	EXPECT_EQ(0, strcmp(ft_itoa(123), "123"));
	EXPECT_EQ(0, strcmp(ft_itoa(+123), "123"));
	EXPECT_EQ(0, strcmp(ft_itoa(2147483647), "2147483647"));
	EXPECT_EQ(0, strcmp(ft_itoa(-2147483648), "-2147483648"));
	EXPECT_EQ(0, strcmp(ft_itoa(0), "0"));
//	system("leaks a.out");
}