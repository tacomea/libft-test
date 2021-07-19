#include "tests.h"

class toupper_class : public ::testing::Test {
protected:

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(LibftTestPart1, tolower)
{
	JUDGE_EQ(tolower, 'a');
	JUDGE_EQ(tolower, '0');
	JUDGE_EQ(tolower, 'A');
	JUDGE_EQ(tolower, 0x00);
}