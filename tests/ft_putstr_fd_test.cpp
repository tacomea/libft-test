#include "tests.h"

class putstr_fd_class : public ::testing::Test {
protected:
	char test[STRSIZE];

	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(putstr_fd_class, putstr_fd)
{
	// char test[10];
	strcpy(test, "42tokyo");

	testing::internal::CaptureStdout();
	ft_putstr_fd(test, 1);
	EXPECT_STREQ("42tokyo", testing::internal::GetCapturedStdout().c_str());

	strcpy(test, "Cursus");
	testing::internal::CaptureStderr();
	ft_putstr_fd(test, 2);
	EXPECT_STREQ("Cursus", testing::internal::GetCapturedStderr().c_str());
}