#include "tests.h"

class strlcat_class : public ::testing::Test {
protected:
	char lib[STRSIZE];
	char test[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strlcat_class, strlcat)
{
	strcpy(lib, "0000000000000000000000000");
	strcpy(test, "0000000000000000000000000");

	JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 0);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 3);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 5);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 0);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 3);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 5);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 0);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 5);
	JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 10);
}