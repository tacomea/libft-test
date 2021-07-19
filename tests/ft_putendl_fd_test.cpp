#include "tests.h"

class putendl_fd_class : public ::testing::Test {
protected:
	char test[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(putendl_fd_class, putendl_fd)
{
	strcpy(test, "42tokyo");
	testing::internal::CaptureStdout();
	ft_putendl_fd(test, 1);
	EXPECT_STREQ("42tokyo\n", testing::internal::GetCapturedStdout().c_str());
	strcpy(test, "Cursus");
	testing::internal::CaptureStderr();
	ft_putendl_fd(test, 2);
	EXPECT_STREQ("Cursus\n", testing::internal::GetCapturedStderr().c_str());
}