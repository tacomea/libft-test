#include "tests.h"

class memmove_class : public ::testing::Test {
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

TEST_F(memmove_class, memmove) {
	JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 5, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", -3, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 0, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 0, 200, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 200, 0, lib, test);
}
