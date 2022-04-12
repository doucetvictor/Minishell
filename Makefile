##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	mysh

SRCS	=	src/cmd.c \
		src/main.c \
		src/minishell1.c \
		src/minishell2.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	-Iinclude/ -Ilib/my/include/
LDLIBS		=	-Llib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C lib/my/
	$(RM) $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re
