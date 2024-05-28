CC = cc 

CFLAGS = -Wall -Wextra -Werror 

DEPS = ft_printf.h


SRC = \
		ft_putchar.c ft_putstr.c ft_putinteger.c ft_printf.c ft_print_unsignedint.c \
		ft_print_ptr_hexa.c ft_print_hexa_caps.c ft_print_int_hexa.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a 

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $?

clean: 
	rm -f $(OBJ)

fclean: 
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 


