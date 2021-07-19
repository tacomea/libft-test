#include "tests.h"

class strncmp_front_class : public ::testing::Test {
protected:
	char test[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strncmp_front_class, strncmp)
{
	JUDGE_EQ_3(strncmp, test, "0123456", 2);
	JUDGE_EQ_3(strncmp, test, "0123456", 5);
	JUDGE_EQ_3(strncmp, test, "0123456", 8);
	JUDGE_EQ_3(strncmp, test, "0123", 0);
	JUDGE_EQ_3(strncmp, test, "0123", 2);
	JUDGE_EQ_3(strncmp, test, "0123", 5);
	JUDGE_EQ_3(strncmp, test, "12", 2);
}