#include "tests.h"

class memcpy_class : public ::testing::Test {
protected:
	char lib[STRSIZE];
	char test[STRSIZE];
	char s[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(memcpy_class, memcpy)
{

	strcpy(lib, "123456789");
	strcpy(test, "123456789");
	strcpy(s, "$$$$$$$");

	memcpy(lib+2, s, 5);
	ft_memcpy(test+2, s, 5);
	EXPECT_STREQ(lib, test);

	EXPECT_EXIT(ft_memcpy(test, NULL, 4), ::testing::KilledBySignal(SIGSEGV),".*"); \
	EXPECT_EXIT(ft_memcpy(NULL, test, 4), ::testing::KilledBySignal(SIGSEGV),".*"); \
	EXPECT_EQ(NULL, (char *)ft_memcpy(NULL, NULL, 4));

}

TEST_F(memcpy_class, error)
{

	EXPECT_EXIT(ft_memcpy(test, NULL, 4), ::testing::KilledBySignal(SIGSEGV),".*"); \
	EXPECT_EXIT(ft_memcpy(NULL, test, 4), ::testing::KilledBySignal(SIGSEGV),".*"); \
	EXPECT_EQ(NULL, (char *)ft_memcpy(NULL, NULL, 4));

}