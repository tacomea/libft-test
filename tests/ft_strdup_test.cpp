#include "tests.h"

class strdup_class : public ::testing::Test {
protected:

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};


TEST_F(strdup_class, strdup)
{
	JUDGE_STR(strdup, "ABC");
	JUDGE_STR(strdup, "");
	JUDGE_STR(strdup, "       ");
	JUDGE_STR(strdup, "abc\0defg");
} 