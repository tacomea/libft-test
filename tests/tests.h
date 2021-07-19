#ifndef TESTS_H
#define TESTS_H

#include "gtest/gtest.h"

extern "C" {
#include "libft.h"
#include <climits>
}
#define JUDGE_EQ(name, val) \
    EXPECT_EQ(name(val), ft_ ## name(val)); \

#define LEAKS_CONFIRM \
    testing::internal::CaptureStdout(); \
	system("leaks a.out"); \
	EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks for 0 total leaked bytes")); \

#endif //TESTS_H
