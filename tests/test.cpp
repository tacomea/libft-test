#include <gtest/gtest.h>
extern "C" {
#include "libft.h"
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
	


// --------------------------------------------------------------------
// |                                                                   |        
// |                           Part 1                                  |
// |                                                                   |
// --------------------------------------------------------------------

class LibftTestPart1 : public ::testing::Test {
protected:
    char lib[STRSIZE];
    char test[STRSIZE];
    char str[STRSIZE];
  
    virtual void SetUp(){
        strcpy(lib, "0123456789");
        strcpy(test, "0123456789");
        strcpy(str, "42 tokyo Cursus Piscine !");
    }
    virtual void TearDown(){
        // testing::internal::CaptureStdout();
        // system("leaks a.out");
        // EXPECT_NE(std::string::npos, testing::internal::GetCapturedStdout().find(" 0 leaks"));
    }
};

TEST_F(LibftTestPart1, isalpha)
{
    JUDGE_EQ(isalpha, 'A');
    JUDGE_EQ(isalpha, 'z');
    JUDGE_EQ(isalpha, '/'); 
    JUDGE_EQ(isalpha, '*'); 
    JUDGE_EQ(isalpha, '0');
    JUDGE_EQ(isalpha, '9');
    JUDGE_EQ(isalpha, '\0');
}

TEST_F(LibftTestPart1, isdigit)
{
    JUDGE_EQ(isdigit, 'A');
    JUDGE_EQ(isdigit, 'z');
    JUDGE_EQ(isdigit, '/'); 
    JUDGE_EQ(isdigit, '*'); 
    JUDGE_EQ(isdigit, '0');
    JUDGE_EQ(isdigit, '9');
    JUDGE_EQ(isdigit, '\0');
}

TEST_F(LibftTestPart1, isalnum)
{
    JUDGE_EQ(isalnum, 'A');
    JUDGE_EQ(isalnum, 'z');
    JUDGE_EQ(isalnum, '/'); 
    JUDGE_EQ(isalnum, '*'); 
    JUDGE_EQ(isalnum, '0');
    JUDGE_EQ(isalnum, '9');
    JUDGE_EQ(isalnum, '\0');
}

TEST_F(LibftTestPart1, isascii)
{
    JUDGE_EQ(isascii, 'A');
    JUDGE_EQ(isascii, 0x00);
    JUDGE_EQ(isascii, 0x7f);
    JUDGE_EQ(isascii, 0x80);
}

TEST_F(LibftTestPart1, isprint)
{
    JUDGE_EQ(isprint, 0x00);
    JUDGE_EQ(isprint, 0x1f);
    JUDGE_EQ(isprint, 0x20);
    JUDGE_EQ(isprint, 0x7f);
}

TEST_F(LibftTestPart1, strlen)
{
    JUDGE_EQ(strlen, "");
    JUDGE_EQ(strlen, "lorem\tipsum\tdolor\nsit\namet\n");
    JUDGE_EQ(strlen, "\f\t\v\r\n ");
    JUDGE_EQ(strlen, "Hello!");
    JUDGE_EQ_DEATH(strlen, NULL);
}

TEST_F(LibftTestPart1, memset)
{
    char s = '$';
    memset(lib+2, s, 5);
    ft_memset(test+2, s, 5);
    EXPECT_STREQ(lib, test);
}

TEST_F(LibftTestPart1, bzero)
{
    bzero(lib+2, 5);
    ft_bzero(test+2, 5);
    EXPECT_STREQ(lib, test);
}

TEST_F(LibftTestPart1, memcpy)
{
    char src[STRSIZE] = "ab\0cde";
    memcpy(lib, src, 5);
    ft_memcpy(test, src, 5);
    EXPECT_STREQ(lib, test);
}

TEST_F(LibftTestPart1, memmove)
{
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 5, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", -3, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 0, 8, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 0, 200, lib, test);
    JUDGE_MEMMOVE(memmove, "abcdefghijklmn42tokyo", 200, 0, lib, test);
}

TEST_F(LibftTestPart1, strlcpy)
{
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 3);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abc", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 3);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdef", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 0);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 5);
    JUDGE_EQ_STR_3(strlcpy, lib, test, "abcdefghijklmn", 10);
}

TEST_F(LibftTestPart1, strlcat)
{
    JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 0);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 3);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abc", 5);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 0);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 3);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdef", 5);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 0);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 5);
    JUDGE_EQ_STR_3(strlcat, lib, test, "abcdefghijklmn", 10);
}

TEST_F(LibftTestPart1, toupper)
{
    JUDGE_EQ(toupper, 'a');
    JUDGE_EQ(toupper, '0');
    JUDGE_EQ(toupper, 'A');
    JUDGE_EQ(toupper, 0x00);
}

TEST_F(LibftTestPart1, tolower)
{
    JUDGE_EQ(tolower, 'a');
    JUDGE_EQ(tolower, '0');
    JUDGE_EQ(tolower, 'A');
    JUDGE_EQ(tolower, 0x00);
}

TEST_F(LibftTestPart1, strchr)
{
    JUDGE_STR_2(strchr, "abcdefghi", '\0');
    JUDGE_STR_2(strchr, "abcdefghi", 'a');
    JUDGE_STR_2(strchr, "abcdefghi", 'z');
}

TEST_F(LibftTestPart1, strrchr)
{
    JUDGE_STR_2(strrchr, "abcdefghi", '\0');
    JUDGE_STR_2(strrchr, "abcdefghi", 'a');
    JUDGE_STR_2(strrchr, "abcdefghi", 'z');
}

TEST_F(LibftTestPart1, strncmp)
{
    JUDGE_EQ_3(strncmp, test, "0123456", 2);
    JUDGE_EQ_3(strncmp, test, "0123456", 5);
    JUDGE_EQ_3(strncmp, test, "0123456", 8);
    JUDGE_EQ_3(strncmp, test, "0123", 0);
    JUDGE_EQ_3(strncmp, test, "0123", 2);
    JUDGE_EQ_3(strncmp, test, "0123", 5);
    JUDGE_EQ_3(strncmp, test, "12", 2);
}

TEST_F(LibftTestPart1, memchr)
{
    JUDGE_EQ_STR_3(memchr, test, test, '3', 2);    
    JUDGE_EQ_STR_3(memchr, test, test, '3', 5);    
    JUDGE_EQ_STR_3(memchr, test, test, ' ', 0);    
    JUDGE_EQ_STR_3(memchr, test, test, ' ', 5);    
    JUDGE_EQ_STR_3(memchr, test, test, 0x00, 1);    
    JUDGE_EQ_STR_3(memchr, test, test, 0x00, 5);    
}

TEST_F(LibftTestPart1, memcmp)
{
    JUDGE_EQ_3(memcmp, test, lib, 0);    
    JUDGE_EQ_3(memcmp, test, lib, 4);   
    JUDGE_EQ_3(memcmp, test, lib, 11);   
    JUDGE_EQ_3(memcmp, test, "0123", 2);   
    JUDGE_EQ_3(memcmp, test, "0123", 5);   
    JUDGE_EQ_3(memcmp, test, "0\t23", 1);   
    JUDGE_EQ_3(memcmp, test, "0\t23", 3);   
}

TEST_F(LibftTestPart1, strnstr)
{
    // str = "42 tokyo Cursus Piscine !";
    JUDGE_EQ_STR_3(strnstr, str, str, "tokyo", 10);
    JUDGE_EQ_STR_3(strnstr, str, str, "toyto", 10);
    JUDGE_EQ_STR_3(strnstr, str, str, "tokyo", 4);
    JUDGE_EQ_STR_3(strnstr, str, str, "", 10);
    JUDGE_EQ_STR_3(strnstr, str, str, "Cursus", 20);
    JUDGE_EQ_STR_3(strnstr, str, str, "Cursus", 20);
    JUDGE_EQ_STR_3(strnstr, str, str, "cursus", 0);
    JUDGE_EQ_STR_3(strnstr, str, str, "cursus", 0);
}

TEST_F(LibftTestPart1, atoi)
{
    JUDGE_EQ(atoi, "000000");
    JUDGE_EQ(atoi, "  ");
    JUDGE_EQ(atoi, "+42");
    JUDGE_EQ(atoi, "2147483647");
    JUDGE_EQ(atoi, "-2147483648");
    JUDGE_EQ(atoi, "2147483648");
    JUDGE_EQ(atoi, "-2147483649");
    JUDGE_EQ(atoi, "-99999999999999999999999");
    JUDGE_EQ(atoi, "99999999999999999999999");
    JUDGE_EQ(atoi, "\t\n\v\f\r 42");
    JUDGE_EQ(atoi, " ---42");
    JUDGE_EQ(atoi, "-+42");
    JUDGE_EQ(atoi, "+234:213");
    JUDGE_EQ(atoi, "fasdataaf2131sfasdf");
}

TEST_F(LibftTestPart1, calloc)
{
    JUDGE_CALLOC(calloc, 0, sizeof(int));
    JUDGE_CALLOC(calloc, 4, sizeof(int));
    JUDGE_CALLOC(calloc, 20, sizeof(char));
}

TEST_F(LibftTestPart1, strdup)
{
    JUDGE_STR(strdup, "ABC");
    JUDGE_STR(strdup, "");
    JUDGE_STR(strdup, "       ");
    JUDGE_STR(strdup, "abc\0defg");
} 


// --------------------------------------------------------------------
// |                                                                   |        
// |                           Part 2                                  |
// |                                                                   |
// --------------------------------------------------------------------

class LibftTestPart2 : public ::testing::Test {
protected:
    char **split;
    char test[BUFSIZ];

    virtual void SetUp(){
    }
    virtual void TearDown(){
    }
};

TEST_F(LibftTestPart2, substr)
{
    // EXPECT_STREQ("", ft_substr(NULL, 1, 1));
    EXPECT_STREQ("", ft_substr("Lorem ipsum dolor sit amet,", 2, 0));
    EXPECT_STREQ("", ft_substr("Lorem ipsum dolor sit amet,", 50, 0));
    EXPECT_STREQ("rem i", ft_substr("Lorem ipsum dolor sit amet,", 2, 5));
    EXPECT_STREQ("or sit amet,", ft_substr("Lorem ipsum dolor sit amet,", 15, 20));
}

TEST_F(LibftTestPart2, strjoin)
{
    EXPECT_EQ(NULL, ft_strjoin(NULL, "42tokyo"));
    EXPECT_EQ(NULL, ft_strjoin("42tokyo", NULL));
    EXPECT_EQ(NULL, ft_strjoin(NULL, NULL));
    EXPECT_STREQ("42tokyo", ft_strjoin("42", "tokyo"));
    EXPECT_STREQ("Cursus", ft_strjoin("Cursus", ""));
    EXPECT_STREQ("Cursus", ft_strjoin("", "Cursus"));
}

TEST_F(LibftTestPart2, strtrim)
{
    EXPECT_EQ(NULL, ft_strtrim(NULL, "42tokyo"));
    EXPECT_EQ(NULL, ft_strtrim("42tokyo", NULL));
    EXPECT_EQ(NULL, ft_strtrim(NULL, NULL));
    EXPECT_STREQ("42tokyo", ft_strtrim("abc42tokyoabc", "abc"));
    EXPECT_STREQ("abc Cursus ABC", ft_strtrim("    abc Cursus ABC   ", " "));
}

TEST_F(LibftTestPart2, split)
{
    split = ft_split("aaa42aatokyoaaa", 'a');
    EXPECT_STREQ("42", split[0]);
    EXPECT_STREQ("tokyo", split[1]);
    split = ft_split(NULL, 'a');
    EXPECT_EQ(NULL, split);
}

TEST_F(LibftTestPart2, itoa)
{
    EXPECT_STREQ("2147483647", ft_itoa(2147483647));
    EXPECT_STREQ("-2147483648", ft_itoa(-2147483648));
    EXPECT_STREQ("0", ft_itoa(0));
}

char	strmapi_func(unsigned int n, char c)
{
	c = c + n;
	return (c);
}

TEST_F(LibftTestPart2, strmapi)
{
    EXPECT_STREQ("acegi", ft_strmapi("abcde", &strmapi_func));
}

void	striteri_func(unsigned int i, char *s)
{
	*s = *s + i;
}

TEST_F(LibftTestPart2, striteri)
{
    strcpy(test, "abcde");
    ft_striteri(test, &striteri_func);
    EXPECT_STREQ("acegi", test);
}

TEST_F(LibftTestPart2, putchar_fd)
{
    testing::internal::CaptureStdout();
    ft_putchar_fd('a', 1);
    EXPECT_STREQ("a", testing::internal::GetCapturedStdout().c_str());
    testing::internal::CaptureStderr();
    ft_putchar_fd('A', 2);
    EXPECT_STREQ("A", testing::internal::GetCapturedStderr().c_str());
}

TEST_F(LibftTestPart2, putstr_fd)
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





// --------------------------------------------------------------------
// |                                                                   |        
// |                          Bonus Part                               |
// |                                                                   |
// --------------------------------------------------------------------

class LibftTestBonus : public ::testing::Test {
protected:
    t_list  *test1;
    t_list  *test2;
    t_list  *test3;
    char    content[STRSIZE];
    virtual void SetUp(){
    }
    virtual void TearDown(){
    }
};

TEST_F(LibftTestBonus, lstnew)
{
    strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    EXPECT_STREQ(content, (char *)test1->content);
    EXPECT_EQ(NULL, test1->next);
}

TEST_F(LibftTestBonus, lstadd_front)
{
    strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);
    ft_lstadd_front(&test1, test2);
    EXPECT_STREQ(content, (char *)test1->content);
    EXPECT_EQ(NULL, test1->next->next);
}

TEST_F(LibftTestBonus, lstsize)
{
    strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);
    ft_lstadd_front(&test1, test2);
    EXPECT_EQ(2, ft_lstsize(test1));
}

// TODO
// TEST_F(LibftTestBonus, lstlast)
// {
//     strcpy(content, "42tokyo");
//     test1 = ft_lstnew(content);
//     strcpy(content, "Cursus");
//     test2 = ft_lstnew(content);    
//     ft_lstadd_front(&test1, test2);
//     EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
//     EXPECT_EQ(NULL, ft_lstlast(test1)->next);
//     free(test1);
// }

TEST_F(LibftTestBonus, lstadd_back)
{
    strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);
    strcpy(content, "Piscine");
    test3 = ft_lstnew(content);
    ft_lstadd_back(&test1, test2);
    ft_lstadd_back(&test1, test3);
    EXPECT_STREQ(content, (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
}
