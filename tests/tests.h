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

#define JUDGE_EQ_3(name, val1, val2, val3) \
    EXPECT_EQ(name(val1, val2, val3), ft_ ## name(val1, val2, val3)); \

#define JUDGE_STR(name, val) \
    EXPECT_STREQ(name(val), ft_ ## name(val));

#define JUDGE_STR_2(name, val1, val2) \
    EXPECT_STREQ(name(val1, val2), ft_ ## name(val1, val2));

#define JUDGE_EQ_STR_3(name, lib, test, val1, val2) \
    EXPECT_EQ(name(lib, val1, val2), ft_ ## name(test, val1, val2)); \
    EXPECT_STREQ(lib, test);

#define JUDGE_EQ_DEATH(name, val) \
    EXPECT_EXIT(ft_ ## name(val), ::testing::KilledBySignal(SIGSEGV),".*"); \
    // EXPECT_EXIT(ft_ ## name(val), ::testing::KilledBySignal(SIGSEGV),".*"); \

#define JUDGE_MEMMOVE(name, str, shift, len, lib, test) \
    strcpy(lib, str); \
    strcpy(test, str); \
    if (0 <= shift) { \
		name(lib+shift, lib, len); \
		ft_ ## name(test+shift, test, len); \
	} \
    else{ \
        name(lib, lib-shift, len); \
		ft_ ## name(test, test-shift, len);\
	} \
    EXPECT_STREQ(lib, test);

#define JUDGE_CALLOC(name, size, byte) \
    EXPECT_EQ(0, memcmp(name(size, byte), ft_ ## name(size, byte), size * byte)); \

#define LEAKS_CONFIRM \
    testing::internal::CaptureStdout(); \
	system("leaks a.out"); \
	EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks for 0 total leaked bytes")); \

#endif //TESTS_H
