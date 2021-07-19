#include "tests.h"

class strchr_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strchr_class, strchr)
{
	JUDGE_STR_2(strchr, "abcdefghi", '\0');
	JUDGE_STR_2(strchr, "abcdefghi", 'a');
	JUDGE_STR_2(strchr, "abcdefghi", 'z');
}
