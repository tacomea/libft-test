#include "tests.h"

class bzero_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(bzero_class, bzero) {
	char tab[100];
	memset(tab, 'a', 100);
	ft_bzero(tab, 0);
	// test 1
	EXPECT_EQ(tab[0], 'a');
	ft_bzero(tab, 1);
	// test 2
	EXPECT_EQ(tab[0], 0);
	// test 3
	EXPECT_EQ(tab[1], 'a');
	LEAKS_CONFIRM
}