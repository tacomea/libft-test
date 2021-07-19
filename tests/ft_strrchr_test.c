#include "tests.h"

class strrchr_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strrchr_class, strrchr)
{
	JUDGE_STR_2(strrchr, "abcdefghi", '\0');
	JUDGE_STR_2(strrchr, "abcdefghi", 'a');
	JUDGE_STR_2(strrchr, "abcdefghi", 'z');
}
