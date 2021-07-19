#include "tests.h"

class isprint_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(isprint_class, print) {
	JUDGE_EQ(isprint, ' ');
	JUDGE_EQ(isprint, '~');
}

TEST_F(isprint_class, non_print) {
	JUDGE_EQ(isprint, ' ' - 1);
	JUDGE_EQ(isprint, '~' + 1);
}