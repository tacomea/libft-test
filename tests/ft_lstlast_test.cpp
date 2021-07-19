#include "tests.h"

class lstlast_class : public ::testing::Test {
protected:
	t_list  *test1;
    t_list  *test2;
    char    content[STRSIZE];
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstlast_class, lstlast) {
	strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);    
    ft_lstadd_front(&test1, test2);
    EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}