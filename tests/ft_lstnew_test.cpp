#include "tests.h"

class lstnew_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstnew_class, lstnew) {
	t_list  *test1;
	char    content[STRSIZE];
	
	strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    EXPECT_STREQ(content, (char *)test1->content);
    EXPECT_EQ(NULL, test1->next);
}