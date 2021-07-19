#include "tests.h"

class lstadd_back_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstadd_back_class, lstadd_back) {
	t_list  *test1;
    t_list  *test2;
    t_list  *test3;
    char    content[STRSIZE];

	strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);
    strcpy(content, "Piscine");
    test3 = ft_lstnew(content);
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
    EXPECT_STREQ(content, (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}