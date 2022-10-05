##
## EPITECH PROJECT, 2022
## my_sokoban Makefile
## File description:
## compiles and builds lib and the source files runs unit tests
##

NAME	=	my_sokoban

SRC	=	source/map/map.c 		 \
		source/game/game.c		 \
		source/game/keys.c		 \
		source/game/check_game.c \
		source/game/box.c

SRC_MAIN = source/main.c

CPPFLAGS = -Wall -Wextra -I./include

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

LIB 	=	-lmy -lprint  -lncurses

DIR	=	-L./lib/

TESTS = ##tests/

TEST_OBJ = $(TESTS:.c=.o)

LIB_TEST = libutest.a

TEST_INCLUDE = -L./ -lmy --coverage -lcriterion

TEST_NAME = unit_test

all: $(OBJ) $(OBJ_MAIN)
	$(MAKE) -C ./lib/my
	$(MAKE) -C ./lib/printf
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(DIR) $(LIB)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)
	$(MAKE) clean -C ./lib/my
	$(MAKE) clean -C ./lib/printf

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my
	$(MAKE) fclean -C ./lib/printf

re: fclean all

unit_tests: fclean $(OBJ) $(TEST_OBJ)
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/printf
		ar rc $(LIB_TEST) $(OBJ)
		gcc -o $(TEST_NAME) $(TESTS) $(TEST_INCLUDE)

tests_run: unit_tests
			./$(TEST_NAME)

unit_clean: fclean
			rm -f $(LIB_TEST)
			rm -f unit_test*
			rm -f $(TEST_OBJ)

.PHONY: all makelib clean fclean re
