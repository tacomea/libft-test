#include "tests.h"

class memchr_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(memchr_class, memchr) {
	char test[STRSIZE];
	strcpy(test, "0123456789");

	JUDGE_EQ_STR_3(memchr, test, test, '3', 2);    
    JUDGE_EQ_STR_3(memchr, test, test, '3', 5);    
    JUDGE_EQ_STR_3(memchr, test, test, ' ', 0);    
    JUDGE_EQ_STR_3(memchr, test, test, ' ', 5);    
    JUDGE_EQ_STR_3(memchr, test, test, 0x00, 1);    
    JUDGE_EQ_STR_3(memchr, test, test, 0x00, 5); 
}