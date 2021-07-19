#include "tests.h"

class strlen_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strlen_class, strlen) {
	JUDGE_EQ(strlen, "");
    JUDGE_EQ(strlen, "lorem\tipsum\tdolor\nsit\namet\n");
    JUDGE_EQ(strlen, "\f\t\v\r\n ");
    JUDGE_EQ(strlen, "Hello!");
    JUDGE_EQ_DEATH(strlen, NULL);
}