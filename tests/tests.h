#ifndef TESTS_H
#define TESTS_H

#include "gtest/gtest.h"

extern "C" {
#include "libft.h"
#include <climits>
}

#define STRSIZE 42 

#define JUDGE_EQ(name, val) \
    EXPECT_EQ(name(val), ft_ ## name(val)); \

#define JUDGE_EQ_STR_3(name, lib, test, val1, val2) \
    EXPECT_EQ(name(lib, val1, val2), ft_ ## name(test, val1, val2)); \
    EXPECT_STREQ(lib, test);

#define LEAKS_CONFIRM \
    testing::internal::CaptureStdout(); \
	system("leaks a.out"); \
	EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks for 0 total leaked bytes")); \

#endif //TESTS_H
