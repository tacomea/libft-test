#include "tests.h"

class strnstr_back_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(strnstr_back_class, strnstr)
{
	// str = "42 tokyo Cursus Piscine !";
	JUDGE_EQ_STR_3(strnstr, str, str, "tokyo", 10);
	JUDGE_EQ_STR_3(strnstr, str, str, "toyto", 10);
	JUDGE_EQ_STR_3(strnstr, str, str, "tokyo", 4);
	JUDGE_EQ_STR_3(strnstr, str, str, "", 10);
	JUDGE_EQ_STR_3(strnstr, str, str, "Cursus", 20);
	JUDGE_EQ_STR_3(strnstr, str, str, "Cursus", 20);
	JUDGE_EQ_STR_3(strnstr, str, str, "cursus", 0);
	JUDGE_EQ_STR_3(strnstr, str, str, "cursus", 0);
}
