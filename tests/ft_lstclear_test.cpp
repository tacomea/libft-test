#include "tests.h"

class lstclear_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){

	}
};

TEST_F(lstclear_class, lstclear) {

	t_list  *test1 = ft_lstnew(malloc(8));
	ft_lstadd_back(&test1, ft_lstnew(malloc(8)));
	ft_lstadd_back(&test1, ft_lstnew(malloc(8)));
	ft_lstadd_back(&test1, ft_lstnew(malloc(8)));

	ft_lstclear(&test1, free);
	EXPECT_EQ(NULL, test1);
	//	free(test1);
	test1 = 0;
	LEAKS_CONFIRM
	//	system("leaks a.out");
}

TEST_F(lstclear_class, error) {
	int a = 100;
	t_list  *test1 = ft_lstnew(&a);

	ft_lstclear(&test1, NULL);
	EXPECT_EQ(NULL, test1);
	//	free(test1);

	ft_lstclear(NULL, free);

	test1 = 0;
	LEAKS_CONFIRM
	//	system("leaks a.out");
}