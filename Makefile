MAIN_PATH	= /usr/local/src/googletest-release-1.11.0/googletest/src/gtest_main.cc
GTEST_PATH	= /usr/local/src/gtest/gtest-all.cc
IN_GUACAMOLE=TRUE

UTILS			= $(addprefix utils/, lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c)
LIBFT_PATH		= ..
FT_HEADER_PATH	= .
HEADER_PATH		= ./tests
TESTS_PATH		= tests/
MANDATORY		= memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd striteri target
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
CFLAGS			= -std=c++11
CC				= gcc

ifeq ($(IN_GUACAMOLE),TRUE)
	MAIN_PATH	= googletest-release-1.11.0/googletest/src/gtest_main.cc
    GTEST_PATH	= gtest/gtest-all.cc
    # FT_HEADER_PATH = ..
endif

$(MANDATORY):
	gcc -c $(LIBFT_PATH)/ft_$@.c
	g++ $(CFLAGS) $(TESTS_PATH)ft_$@_test.cpp $(MAIN_PATH) $(GTEST_PATH) -I$(FT_HEADER_PATH) ft_$@.o
	@./a.out
	@rm -f a.out ft_$@.o

$(BONUS):
	gcc -c $(LIBFT_PATH)/ft_$@.c
	g++ $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$@_test.cpp $(MAIN_PATH) $(GTEST_PATH) -I$(FT_HEADER_PATH) ft_$@.o
	@./a.out
	@rm -f a.out ft_$@.o

init:
	curl -OL 'https://github.com/google/googletest/archive/release-1.11.0.tar.gz'
	tar zxvf release-1.11.0.tar.gz
	rm -f release-1.11.0.tar.gz
	IN_GUACAMOLE=TRUE
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py ./

.PHONY: all init
