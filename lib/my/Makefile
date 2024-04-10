##
## EPITECH PROJECT, 2023
## Day10, Task01
## File description:
## makefile pour la librairie
##

NAME	=	libmy.a

SRCS	=	my_putstr.c	\
		my_strlen.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_swap_char.c	\
		my_put_float.c	\
		my_put_scientific.c	\
		my_put_scientific_maj.c	\
		my_put_octal.c	\
		my_put_hexadecimal.c	\
		my_put_hexadecimal_maj.c	\
		my_put_adress.c	\
		my_put_nbr_pos.c	\
		my_printf.c	\
		my_put_g.c	\
		my_put_g_maj.c	\
		my_putchar_in_struct.c	\
		my_putstr_in_struct.c	\
		my_put_nbr_in_struct.c	\
		my_put_float_in_struct.c	\
		my_put_scientific_in_struct.c	\
		my_put_scientific_maj_in_struct.c	\
		my_put_g_in_struct.c	\
		my_put_g_maj_in_struct.c	\
		my_put_octal_in_struct.c	\
		my_put_nbr_pos_in_struct.c	\
		my_put_adress_in_struct.c	\
		print_percent_in_struct.c	\
		my_strdup.c	\
		my_strndup.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

CPPFLAGS	=	-I./include

all:	 $(NAME)

$(NAME):	$(OBJS)
	@$(CC) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@cp $(NAME) ../../

clean:
	@$(RM)  $(OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:	fclean all
