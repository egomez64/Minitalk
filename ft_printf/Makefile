NAME = libftprintf.a

CC = cc

SRCS = ft_converttreatment.c ft_printf.c ft_printchar.c ft_printnbr.c ft_putnbr_hex.c ft_putptr_hex.c\
ft_putstr.c ft_uputnbr.c
	
HEADERS = ft_printf.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
