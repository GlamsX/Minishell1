##
## EPITECH PROJECT, 2019
## PSU_minishell1_2018
## File description:
## Makefile
##

NAME	=	mysh

CFLAGS	+=	-W -Wextra -g -Wall -I./include

SRC	=	lib/basic_funcs.c	\
		lib/my_str_to_word_array.c	\
		lib/get_next_line.c	\
		src/builtins/cd/cd.c	\
		src/builtins/setenv/setenv.c	\
		src/builtins/unsetenv/unsetenv.c	\
		src/builtins/env/my_env.c	\
		src/builtins/exit/exit.c	\
		src/fork_path.c	\
		src/init_env.c	\
		src/linkedlist/linked_list.c	\
		src/linkedlist/linked_list_2.c	\
		src/linkedlist/my_strlen_for_list.c	\
		src/free_foncs.c	\
		src/execution.c	\
		src/builtins/setenv/exec_setenv.c	\
		src/main.c

PRINTF	=	my_printf/src/my_printf.c	\
			my_printf/src/check_str.c	\
			my_printf/src/mod_1.c	\
			my_printf/src/mod_2.c	\
			my_printf/src/call_format.c	\
			my_printf/src/call_format_u.c	\
			my_printf/lib/my_print_base.c	\
			my_printf/lib/my_print_longs.c	\
			my_printf/lib/my_print_special.c	\
			my_printf/lib/my_prints_basics.c	\
			my_printf/lib/utils.c	\
			my_printf/lib/getstr.c

OBJ	=	$(SRC:.c=.o) $(PRINTF:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
