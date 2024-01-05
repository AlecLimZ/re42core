# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leng-chu <leng-chu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:30:53 by leng-chu          #+#    #+#              #
#    Updated: 2024/01/05 13:17:17 by leng-chu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC = gcc
CC_STRICT = $(CC) \
			$(CCF_INCLUDES) \
			$(CCF_STRICT)

CC_FULL = $(CC_STRICT) \
		  $(CCF_DDEBUG)

CCF_INCLUDES = -I $(LIBFT_INCLUDES) -I $(INCLUDES_PATH)
CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -03
CCF_DEBUG = -g -fsanitize=leak

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives

LIBS_PATH = ./libs

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES = $(LIBFT_PATH)/includes

######################################################################################
# MANDATORY
######################################################################################

M_HEADER = $(INCLUDES_PATH)/push_swap.h
M_ARCHIVE = $(ARCHIVES_PATH)/push_swap.a

M_SOURCES_PATH = $(SOURCES_PATH)/mandatory
M_OBJECTS_PATH = $(OBJECTS_PATH)/mandatory

M_SOURCES = $(wildcard $(M_SOURCES_PATH)/**/*.c) $(wildcard $(M_SOURCES_PATH)/*.c)

M_OBJECTS = $(patsubst $(M_SOURCES_PATH)/%.c, $(M_OBJECTS_PATH)/%.o, $(M_SOURCES))
M_OBJECT_DIRECTORIES = $(sort $(dir $(M_OBJECTS)))

M_MAIN = ./main.c

M_ARCHIVES = $(M_ARCHIVE) $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE)
	$(CC_FULL) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

$(M_ARCHIVE): $(M_HEADER) $(M_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(M_ARCHIVE) $(M_OBJECTS)

$(M_OBJECTS_PATH)/%.o: $(M_SOURCES_PATH)/%.c
	$(CC_FULL) -c -o $@ $<

clean:
	$(REMOVE) $(M_OBJECTS)
	$(REMOVE) $(M_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

######################################################################################
# BONUS
######################################################################################

B_NAME = checker

B_HEADER = $(INCLUDES_PATH)/push_swap_bonus.h
B_ARCHIVE = $(ARCHIVES_PATH)/push_swap_bonus.a

B_SOURCES_PATH = $(SOURCES_PATH)/bonus
B_OBJECTS_PATH = $(OBJECTS_PATH)/bonus

B_SOURCES = $(wildcard $(B_SOURCES_PATH)/**/*.c) $(wildcard $(B_SOURCES_PATH)/*.c)

B_OBJECTS = $(patsubst $(B_SOURCES_PATH)/%.c, $(B_OBJECTS_PATH)/%.o, $(B_SOURCES))
B_OBJECT_DIRECTORIES = $(sort $(dir $(B_OBJECTS)))

B_MAIN = ./main_bonus.c

B_ARCHIVES = $(B_ARCHIVE) $(LIBFT)

allb: bonus

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(B_ARCHIVE)
	$(CC_STRICT) $(CCF_DEBUG) \
		$(CCF_INCLUDES) \
		$(B_MAIN) \
		$(B_ARCHIVES) \
		-o $(B_NAME)

$(B_ARCHIVE): $(B_HEADER) $(B_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(B_ARCHIVE) $(B_OBJECTS)

$(B_OBJECTS_PATH)/%.o: $(B_SOURCES_PATH)/%.c
	$(CC_STRICT) $(CCF_INCLUDES) -c -o $@ %<

cleanb:
	$(REMOVE) $(B_OBJECTS)
	$(REMOVE) $(B_ARCHIVE)

fcleanb: cleanb
	$(REMOVE) $(B_NAME)

reb: fcleanb bonus

######################################################################################
# DIRS
######################################################################################

dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) \
	$(M_OBJECT_DIRECTORIES) $(B_OBJECT_DIRECTORIES)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(M_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(B_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

######################################################################################
# CLEAN
######################################################################################

tclean:	clean_libs fclean fclean b tests_clean example_clean vglog_clean

######################################################################################
# LIBS
######################################################################################

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean_libs: libft_clean

######################################################################################
# TESTS
######################################################################################

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/*.c)
CCF_TEST_LIBS = -lrt -lm
EXECUTE_TESTS = ./test

build_tests: re
	$(CC_FULL) \
		$(TEST_SOURCES) \
		$(M_ARCHIVES) \
		$(CCF_TEST_LIBS) \
		-o $(EXECUTE_TESTS)

test: build_tests
	$(EXECUTE_TESTS)

tests_clean:
	$(REMOVE_RECURSIVE) $(EXECUTE_TESTS)

######################################################################################
# EXAMPLE
######################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(M_ARCHIVE)
	$(CC_FULL) \
		$(EXAMPLE_MAIN) \
		$(M_ARCHIVES)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

######################################################################################
# VALGRIND
######################################################################################

CC_VG = $(CC) \
		$(CCF_INCLUDES) \
		$(CCF_STRICT)

VG = valgrind
VG_FLAGS = --leak-check=full --show-leak-kinds=all --trace-children=yes
VG_LOG = valgrind_leaks.log
VG_LOG_FLAGS = --log-file=$(VG_LOG) \
			   --leak-check=full \
			   --show-leak-kinds=all \
			   --trace-children=yes \
			   --track-origins=yes \
			   --verbose

VG_TARGET = ./push_swap $(shell ruby -e "puts (1..100).to_a.shuffle.join(' ')")

vg: vg_build
	$(VG) $(VG_FLAGS) $(VG_TARGET)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET)

vg_build: $(LIBFT) $(M_ARCHIVE)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

######################################################################################
# MISC
######################################################################################

norm:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) norm
	@printf "\n$(G)=== No norminette errors found in $(LIBFT_PATH) ===$(RC)\n\n"
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(M_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(M_MAIN) ===$(RC)\n\n"
	norminette $(B_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(B_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo ====== MANDATORY =========
	@echo "M_SOURCES = $(M_SOURCES)"
	@echo ======== BONUS ==========
	@echo "B_SOURCES = $(B_SOURCES)"
	@echo =========================

######################################################################################
# PHONY
######################################################################################

.PHONY: \
all clean fclean re \
\
allb bonus clean b fcleanb reb \
\
dirs \
\
tclean \
\
libft_clean clean_libs \
\
build_tests test tests_clean \
\
example build_example example_clean \
\
vg vglog vg_build vglog_clean \
\
norm git gitm dump_sources

######################################################################################
# Colors
######################################################################################


