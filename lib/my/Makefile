##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	libmy.a

SRCS	=	src/my_compute_power_rec.c \
		src/my_compute_square_root.c \
		src/my_find_prime_sup.c \
		src/my_getnbr.c \
		src/my_isneg.c \
		src/my_is_prime.c \
		src/my_nbr_to_str.c \
		src/my_putchar.c \
		src/my_put_nbr.c \
		src/my_putstr.c \
		src/my_read_file.c \
		src/my_revstr.c \
		src/my_show_word_array.c \
		src/my_sort_int_array.c \
		src/my_strcapitalize.c \
		src/my_strcat.c \
		src/my_strcmp.c \
		src/my_str_combine.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_str_isalpha.c \
		src/my_str_islower.c \
		src/my_str_isnum.c \
		src/my_str_isprintable.c \
		src/my_str_isupper.c \
		src/my_strlen.c \
		src/my_strlowcase.c \
		src/my_strncat.c \
		src/my_strncmp.c \
		src/my_strncpy.c \
		src/my_str_no_trailing_space.c \
		src/my_str_split.c \
		src/my_strstr.c \
		src/my_str_to_word_array.c \
		src/my_strupcase.c \
		src/my_swap.c

OBJS	=	$(SRCS:.c=.o)

AR		=	ar rc
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	-Iinclude/

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
