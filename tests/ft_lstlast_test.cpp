#include "tests.h"

class lstlast_class : public ::testing::Test {
protected:
	t_list  *test1;
    t_list  *test2;
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstlast_class, lstlast) {
	test1 = ft_lstnew((void *)"42tokyo");
	test2 = ft_lstnew((void *)"Cursus");
    ft_lstadd_front(&test1, test2);
    EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}