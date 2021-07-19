#include "tests.h"
#include <string.h>


class calloc_class : public ::testing::Test {
protected:
	virtual void SetUp(){
	}
	virtual void TearDown(){
	}
};

TEST_F(calloc_class, calloc) {
	char *p1 = (char *)calloc(3, 2);
	char p2[] = {0,0,0,0,0,0};
	// test1
	EXPECT_EQ(0, memcmp(p1, p2, 6));

	// test2
	// make sure to check that ft_calloc only takes memory of specified size

	testing::internal::CaptureStdout();
	system("leaks a.out");
	EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks for 0 total leaked bytes"));
	
//	system("leaks a.out | grep 'leaks for'");
//	EXPECT_STREQ(" 0 leaks for 0 total leaked bytes.\n", strstr(testing::internal::GetCapturedStdout().c_str(), " 0 leaks for 0 total leaked bytes"));
//	std::cout << "leaks test result: \n\n" << leaks.find("leaks Report") << "\nend\n\n";
}