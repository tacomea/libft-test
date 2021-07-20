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
	t_list  *test2;
	char    *content = (char *)malloc(8);
	for (int i = 0; i < 8; i++) {
		content[i] = i + '0';
	}


	test1 = ft_lstnew(content);
	ft_lstdelone(test1, free);

}