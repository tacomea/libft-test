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
