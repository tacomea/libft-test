#include "tests.h"

class lstmap_class : public ::testing::Test {
protected:
	t_list  *test1;
    t_list  *test2;
    t_list  *test3;
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstmap_class, lstmap) {
    test1 = ft_lstnew(strdup("42tokyo"));
    test2 = ft_lstnew(strdup("Cursus"));
    test3 = ft_lstnew(strdup("Piscine"));
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
    EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}

