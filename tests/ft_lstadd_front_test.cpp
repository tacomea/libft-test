#include "tests.h"

class lstadd_front_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstadd_front_class, lstadd_front) {
	t_list  *test1;
	t_list  *test2;


    test1 = ft_lstnew((void *)"42tokyo");
    test2 = ft_lstnew((void *)"Cursus");
    ft_lstadd_front(&test1, test2);
    EXPECT_STREQ("Cursus", (char *)test1->content);
    EXPECT_EQ(NULL, test1->next->next);
}