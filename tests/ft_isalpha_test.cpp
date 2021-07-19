#include "tests.h"

class isalpha_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(isalpha_class, alpha) {
	JUDGE_EQ(isalpha, 'a');
	JUDGE_EQ(isalpha, 'z');
	JUDGE_EQ(isalpha, 'A');
	JUDGE_EQ(isalpha, 'Z');
}

TEST_F(isalpha_class, non_alpha) {
	JUDGE_EQ(isalpha, 'a' - 1);
	JUDGE_EQ(isalpha, 'z' + 1);
	JUDGE_EQ(isalpha, 'A' - 1);
	JUDGE_EQ(isalpha, 'Z' + 1);
}