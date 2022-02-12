##
## EPITECH PROJECT, 2022
## my_project
## File description:
## Makefile
##

SRC			=	src/check_map.c				\
				src/check_victory.c			\
				src/fit_in_screen.c			\
				src/generate.c				\
				src/my_sokoban.c			\
				src/positions.c				\
				src/status.c				\
				src/movement/can_go.c		\
				src/movement/move_down.c	\
				src/movement/move_left.c	\
				src/movement/move_right.c	\
				src/movement/move_up.c		\

CRITERION	=	$(wildcard tests/*.c)

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

# -Wall
CFLAGS		+=	-W -Wextra -Werror -Wshadow -Wimplicit -pedantic

LDFLAGS		+=	-L./lib -lutils
LDFLAGS		+=	-L./lib -llinkedlist
LDFLAGS		+=	-lncurses

CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-g

all:			lib	$(NAME)
PHONY		+=	all

lib:
				make -C ./lib/
PHONY		+=	lib

$(NAME):		$(OBJ)
				gcc src/main.c $^ -o $@ -ggdb3 $(CPPFLAGS) $(LDFLAGS)

debug:			CPPFLAGS += -ggdb3
debug:			CPPFLAGS += -g
debug:			lib	$(OBJ)
				gcc src/main.c $(OBJ) -o $@ $(CPPFLAGS) $(LDFLAGS)
				valgrind ./$@
PHONY		+=	debug

tests_run:		CPPFLAGS += --coverage
tests_run:		CPPFLAGS += -lcriterion
tests_run:		lib
				gcc -o uts $(SRC) $(CRITERION) $(CPPFLAGS) $(LDFLAGS)
				-./uts
				rm -f uts
PHONY		+=	tests_run

cover:
				mkdir -p covr
				gcovr --exclude tests/ --html --html-details -o covr/cover.html
				gcovr --branches --exclude tests/
				make -C ./ clean
PHONY		+=	cover

clean:
				make -s -C ./lib/ clean
				@find . -type f | xargs touch
				@rm -f $(OBJ)
				@rm -f *.o
				@rm -f *~
				@rm -f vgcore*
				@rm -f #*
				@rm -f *.gcda
				@rm -f *.identifier
				@rm -f *.gcno
PHONY		+=	clean

fclean:			clean
				make -s -C ./lib/ fclean
				rm -f $(NAME)
				@rm -f covr/*.html
				@rm -f covr/*.css
				@rm -rf covr/
				@rm -f *Zone.Identifier
				@rm -f projet
				@rm -f *.gcno
PHONY		+=	fclean

my_tests: 		tests_run cover
PHONY		+=	my_tests

re:				fclean all
PHONY		+=	re

run:			all
				-./$(NAME) map
PHONY		+=	run

.PHONY:			$(PHONY)
