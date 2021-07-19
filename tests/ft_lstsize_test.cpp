#include "tests.h"

class lstsize_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};


TEST_F(lstsize_class, lstsize) {
	t_list  *test1;
    t_list  *test2;
    char    content[STRSIZE];

	strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);
    ft_lstadd_front(&test1, test2);
    EXPECT_EQ(2, ft_lstsize(test1));
}