
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

// TODO
TEST_F(LibftTestBonus, lstlast)
{
    strcpy(content, "42tokyo");
    test1 = ft_lstnew(content);
    strcpy(content, "Cursus");
    test2 = ft_lstnew(content);    
    ft_lstadd_front(&test1, test2);
    EXPECT_STREQ("42tokyo", (char *)ft_lstlast(test1)->content);
    EXPECT_EQ(NULL, ft_lstlast(test1)->next);
    // free(test1);
}
