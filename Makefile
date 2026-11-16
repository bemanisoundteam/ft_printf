NAME = libftprintf.a
LIBFT = libft/libft.a
SOURCES = ft_printf.c ft_printformatted.c printers/ft_print_chr.c printers/ft_print_str.c printers/ft_print_ptr.c printers/ft_print_base.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS += -I libft -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJECTS)
	$(AR) rcs $(NAME) $(LIBFT) $(OBJECTS)

clean:
	$(MAKE) -C libft $@
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C libft $@
	rm -f $(NAME)

re: fclean all
