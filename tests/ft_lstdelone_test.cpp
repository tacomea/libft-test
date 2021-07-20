#include "tests.h"

class lstdelone_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
		LEAKS_CONFIRM
	}
};

TEST_F(lstdelone_class, lstdelone) {
	t_list  *test1;

	test1 = ft_lstnew(malloc(8));
	ft_lstdelone(test1, free);

}