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
	char	*str = (char *)content;
	int		i = 0;

	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = 'A' + (str[i] - 'a');
		i++;
	}
	return ((void *)str);
}

TEST_F(lstmap_class, lstmap) {
    test1 = ft_lstnew(strdup("42tokyo"));
    test2 = ft_lstnew(strdup("Cursus"));
    test3 = ft_lstnew(strdup("  hoge -- foo\t++ 3"));
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
	res = ft_lstmap(test1, &lstiter_func, free);
	EXPECT_STREQ("42TOKYO", (char *)res->content);
    EXPECT_STREQ("CURSUS", (char *)res->next->content);
    EXPECT_STREQ("  HOGE -- FOO\t++ 3", (char *)res->next->next->content);
}

