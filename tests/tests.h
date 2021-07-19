#ifndef TESTS_H
#define TESTS_H

#include "gtest/gtest.h"

extern "C" {
#include "libft.h"
#include <climits>
}
#define JUDGE_EQ(name, val) \
    EXPECT_EQ(name(val), ft_ ## name(val)); \

#endif //TESTS_H
