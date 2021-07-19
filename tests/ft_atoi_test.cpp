#include "tests.h"

class atoi_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(atoi_class, atoi) {
	JUDGE_EQ(atoi, " \t-123");
	JUDGE_EQ(atoi, " \t+123");
	JUDGE_EQ(atoi, " \t+123");
	JUDGE_EQ(atoi, "2147483647");
	JUDGE_EQ(atoi, "-2147483648");
	JUDGE_EQ(atoi, "-2147a483648");
	JUDGE_EQ(atoi, "-2147 483648");
	JUDGE_EQ(atoi, "0");
	JUDGE_EQ(atoi, " \t--123");
	JUDGE_EQ(atoi, " \t++123");
	JUDGE_EQ(atoi, "2147483648");
	JUDGE_EQ(atoi, "-2147483649");
	JUDGE_EQ(atoi, "- 2147483648");
	JUDGE_EQ(atoi, "9223372036854775807");
	JUDGE_EQ(atoi, "9223372036854775808");
	JUDGE_EQ(atoi, "-9223372036854775807");
	JUDGE_EQ(atoi, "-9223372036854775808");
	JUDGE_EQ(atoi, "-9223372036854775809");
	system("leaks a.out");
}