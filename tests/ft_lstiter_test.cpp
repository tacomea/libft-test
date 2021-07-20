#include "tests.h"

class lstiter_class : public ::testing::Test {
protected:
	t_list  *test1;
    t_list  *test2;
	t_list	*test3;
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

void	lstiter_func(void *content)
{
	char	*str = (char *)content;

	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
			*str = 'A' + (*str = 'a');
		str++;
	}
}

TEST_F(lstiter_class, lstiter) {
    test1 = ft_lstnew((void *)"42tokyo");
    test2 = ft_lstnew((void *)"Cursus");    
    test3 = ft_lstnew((void *)"  hoge -- foo\t++ 3");    
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
	ft_lstiter(test1, &lstiter_func);
    EXPECT_STREQ("42TOKYO", (char *)test1->content);
    EXPECT_STREQ("CURSUS", (char *)test1->next->content);
    EXPECT_STREQ("  HOGE -- FOO\t++ 3", (char *)test1->next->next->content);
}