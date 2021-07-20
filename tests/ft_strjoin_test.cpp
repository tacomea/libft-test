#include "tests.h"

class strjoin_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(strjoin_class, strjoin)
{
	EXPECT_EQ(NULL, ft_strjoin(NULL, "42tokyo"));
//	EXPECT_EQ(NULL, ft_strjoin("42tokyo", NULL));
//	EXPECT_EQ(NULL, ft_strjoin(NULL, NULL));
	EXPECT_STREQ("42tokyo", ft_strjoin("42", "tokyo"));
	EXPECT_STREQ("Cursus", ft_strjoin("Cursus", ""));
	EXPECT_STREQ("Cursus", ft_strjoin("", "Cursus"));
}
