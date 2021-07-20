MAIN_PATH	= /usr/local/src/googletest-release-1.11.0/googletest/src/gtest_main.cc
GTEST_PATH	= /usr/local/src/gtest/gtest-all.cc
IN_GUACAMOLE=TRUE

UTILS			= $(addprefix utils/, lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c lstdelone.c lstclear.c lstiter.c lstmap.c)
LIBFT_PATH		= ..
FT_HEADER_PATH	= .
HEADER_PATH		= ./tests
MANDATORY		= memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd striteri target
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap

SRCNAME			= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c\
				ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c
B_SRCNAME		= ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
				ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SRCS    		= $(addprefix $(LIBFT_PATH)/, $(SRCNAME))
B_SRC			= $(addprefix $(LIBFT_PATH)/, $(B_SRCNAME))

OBJS    		= $(SRCNAME:%.c=%.o)
B_OBJS			= $(B_SRCNAME:%.c=%.o)
CFLAGS			= -std=c++11
CC				= gcc
GCCFLAG   		= -Wall -Wextra -Werror

TEST_SRCNAME	= ft_isascii_test.cpp ft_isprint_test.cpp ft_isalpha_test.cpp ft_isdigit_test.cpp ft_isalnum_test.cpp \
				ft_tolower_test.cpp ft_toupper_test.cpp ft_strlen_test.cpp ft_strlcpy_test.cpp ft_strlcat_test.cpp \
				ft_strchr_test.cpp ft_strrchr_test.cpp ft_strnstr_test.cpp ft_strncmp_test.cpp ft_atoi_test.cpp \
				ft_memset_test.cpp ft_bzero_test.cpp ft_memcpy_test.cpp ft_memmove_test.cpp ft_striteri_test.cpp\
				ft_memchr_test.cpp ft_memcmp_test.cpp ft_strdup_test.cpp ft_calloc_test.cpp ft_itoa_test.cpp \
				ft_putchar_fd_test.cpp ft_putstr_fd_test.cpp ft_putendl_fd_test.cpp ft_putnbr_fd_test.cpp \
				ft_substr_test.cpp ft_strjoin_test.cpp ft_strtrim_test.cpp ft_split_test.cpp ft_strmapi_test.cpp

TEST_B_SRCNAME	= ft_lstsize_test.cpp ft_lstlast_test.cpp ft_lstadd_front_test.cpp ft_lstadd_back_test.cpp \
				ft_lstnew_test.cpp ft_lstdelone_test.cpp ft_lstclear_test.cpp ft_lstiter_test.cpp ft_lstmap_test.cpp
TESTS_PATH		= tests/
TEST_SRCS   	= $(addprefix $(TESTS_PATH), $(TEST_SRCNAME))
TEST_B_SRCS   	= $(addprefix $(TESTS_PATH), $(TEST_B_SRCNAME))


ifeq ($(IN_GUACAMOLE),TRUE)
	MAIN_PATH	= googletest-release-1.11.0/googletest/src/gtest_main.cc
    GTEST_PATH	= gtest/gtest-all.cc
    # FT_HEADER_PATH = ..
endif

m: mstart
	g++ $(CFLAGS) $(TEST_SRCS) $(MAIN_PATH) $(GTEST_PATH) -L$(LIBFT_PATH) -lft
	@./a.out
	@rm -f a.out *.o

b: mstart
	g++ $(CFLAGS) $(TEST_B_SRCS) $(MAIN_PATH) $(GTEST_PATH) -L$(LIBFT_PATH) -lft
	@./a.out
	@rm -f a.out *.o

$(MANDATORY): mstart
	g++ $(CFLAGS) $(TESTS_PATH)ft_$@_test.cpp $(MAIN_PATH) $(GTEST_PATH) -L$(LIBFT_PATH) -lft
	@./a.out
	@rm -f a.out ft_$@.o

$(BONUS): bstart
	g++ $(CFLAGS) $(TESTS_PATH)ft_$@_test.cpp $(MAIN_PATH) $(GTEST_PATH) -L$(LIBFT_PATH) -lft
	@./a.out
	@rm -f a.out ft_$@.o

init:
	curl -OL 'https://github.com/google/googletest/archive/release-1.11.0.tar.gz'
	tar zxvf release-1.11.0.tar.gz
	rm -f release-1.11.0.tar.gz
	IN_GUACAMOLE=TRUE
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py ./

mstart:
	make -C $(LIBFT_PATH)

bstart:
	make bonus -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)

.PHONY: all init
