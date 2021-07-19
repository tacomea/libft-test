#include "tests.h"

class memcmp_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(memcmp_class, memcmp) {
	char lib[STRSIZE];
    char test[STRSIZE];

	strcpy(lib, "0123456789");
    strcpy(test, "0123456789");
	JUDGE_EQ_3(memcmp, test, lib, 0);    
    JUDGE_EQ_3(memcmp, test, lib, 4);   
    JUDGE_EQ_3(memcmp, test, lib, 11);   
    JUDGE_EQ_3(memcmp, test, "0123", 2);   
    JUDGE_EQ_3(memcmp, test, "0123", 5);   
    JUDGE_EQ_3(memcmp, test, "0\t23", 1);   
    JUDGE_EQ_3(memcmp, test, "0\t23", 3);  
}