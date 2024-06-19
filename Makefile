CC = cc 

CFLAGS = -Wall -Wextra -Werror 

DEPS = ft_printf.h

LIBFT = Libft

SRC = \
		ft_putchar.c ft_putstr.c ft_putinteger.c ft_printf.c ft_print_unsignedint.c \
		ft_print_ptr_hexa.c ft_print_hexa_caps.c ft_print_int_hexa.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a 

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp Libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)
%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $?

clean: 
	@make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: 
	@make fclean -C $(LIBFT)
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re 


