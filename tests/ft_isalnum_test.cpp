#include "tests.h"

class isalnum_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(isalnum_class, alnum) {
	JUDGE_EQ(isalnum, 'a');
	JUDGE_EQ(isalnum, 'z');
	JUDGE_EQ(isalnum, 'A');
	JUDGE_EQ(isalnum, 'Z');
	JUDGE_EQ(isalnum, '0');
	JUDGE_EQ(isalnum, '9');
}

TEST_F(isalnum_class, non_alnum) {
	JUDGE_EQ(isalnum, 'a' - 1);
	JUDGE_EQ(isalnum, 'z' + 1);
	JUDGE_EQ(isalnum, 'A' - 1);
	JUDGE_EQ(isalnum, 'Z' + 1);
	JUDGE_EQ(isalnum, '0' - 1);
	JUDGE_EQ(isalnum, '9' + 1);
}