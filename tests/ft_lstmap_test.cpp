#include "tests.h"

class lstmap_class : public ::testing::Test {
protected:
	t_list  *test1;
    t_list  *test2;
    t_list  *test3;
	t_list	*res;
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

void	*lstiter_func(void *content)
{
	unsigned char	*str = (unsigned char *)content;

	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
			*str = 'A' + (*str - 'a');
		str++;
	}
}

TEST_F(lstmap_class, lstmap) {
    test1 = ft_lstnew(strdup("42tokyo"));
    test2 = ft_lstnew(strdup("Cursus"));
    test3 = ft_lstnew(strdup("  hoge -- foo\t++ 3"));
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
	res = ft_lstmap(test1, )
    EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}

