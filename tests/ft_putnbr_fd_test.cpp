#include "tests.h"

class putnbr_fd_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(putnbr_fd_class, putnbr_fd)
{
	testing::internal::CaptureStdout();
	ft_putnbr_fd(2147483647, 1);
	EXPECT_STREQ("2147483647", testing::internal::GetCapturedStdout().c_str());
	testing::internal::CaptureStdout();
	ft_putnbr_fd(0, 1);
	EXPECT_STREQ("0", testing::internal::GetCapturedStdout().c_str());
	testing::internal::CaptureStderr();
	ft_putnbr_fd(-2147483648, 2);
	EXPECT_STREQ("-2147483648", testing::internal::GetCapturedStderr().c_str());
}