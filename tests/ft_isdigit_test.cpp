#include "tests.h"

class isdigit_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(isdigit_class, digit) {
	JUDGE_EQ(isdigit, '0');
	JUDGE_EQ(isdigit, '9');
}

TEST_F(isdigit_class, non_digit) {
	JUDGE_EQ(isdigit, '0' - 1);
	JUDGE_EQ(isdigit, '9' + 1);
}