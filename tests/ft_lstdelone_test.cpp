#include "tests.h"

class lstdelone_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){

	}
};

TEST_F(lstdelone_class, lstdelone) {
	t_list  *test1;

	test1 = ft_lstnew(malloc(8));
	ft_lstdelone(test1, free);
//	free(test1);
	test1 = 0;
	LEAKS_CONFIRM
//	system("leaks a.out");
}