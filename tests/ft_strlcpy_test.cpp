#include "tests.h"

class strlcpy_class : public ::testing::Test {
protected:
	char lib[STRSIZE];
    char test[STRSIZE];
	virtual void SetUp(){
		strcpy(lib, "0123456789");
        strcpy(test, "0123456789");
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strlcpy_class, strlcpy) {
	JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 3);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 3);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 10);
}