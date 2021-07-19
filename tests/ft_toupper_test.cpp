#include "tests.h"

class toupper_class : public ::testing::Test {
	protected:

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(toupper_class, toupper)
{
	JUDGE_EQ(toupper, 'a');
	JUDGE_EQ(toupper, '0');
	JUDGE_EQ(toupper, 'A');
	JUDGE_EQ(toupper, 0x00);
}