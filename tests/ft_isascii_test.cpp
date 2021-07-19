#include "tests.h"

class isascii_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(isascii_class, ascii) {
	JUDGE_EQ(isascii, 0);
	JUDGE_EQ(isascii, 127);
}

TEST_F(isascii_class, non_ascii) {
	JUDGE_EQ(isascii, 0 - 1);
	JUDGE_EQ(isascii, 127 + 1);
}