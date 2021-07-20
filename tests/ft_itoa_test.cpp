#include "tests.h"

class itoa_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(itoa_class, itoa) {
	char *s = ft_itoa(-123);
	EXPECT_EQ(0, strcmp(s, "-123"));
	free(s);

	s = ft_itoa(123);
	EXPECT_EQ(0, strcmp(s, "123"));
	free(s);

	s = ft_itoa(+123);
	EXPECT_EQ(0, strcmp(s, "123"));
	free(s);

	s = ft_itoa(2147483647);
	EXPECT_EQ(0, strcmp(s, "2147483647"));
	free(s);


	s = ft_itoa(-2147483648);
	EXPECT_EQ(0, strcmp(s, "-2147483648"));
	// free(s);


	s = ft_itoa(0);
	EXPECT_EQ(0, strcmp(s, "0"));
	// free(s);
}