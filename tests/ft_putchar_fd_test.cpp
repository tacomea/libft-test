#include "tests.h"

class putchar_fd_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(putchar_fd_class, putchar_fd)
{
	testing::internal::CaptureStdout();
	ft_putchar_fd('a', 1);
	EXPECT_STREQ("a", testing::internal::GetCapturedStdout().c_str());
	testing::internal::CaptureStderr();
	ft_putchar_fd('A', 2);
	EXPECT_STREQ("A", testing::internal::GetCapturedStderr().c_str());
}
