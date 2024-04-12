NAME = minitalk

CC = cc

SERVER_SRCS = server.c

CLIENT_SRCS = client.c

HEADERS = minitalk.h

SERVER_NAME = server

CLIENT_NAME = client

LIBFT_PATH = libft

LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ft_printf

FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

ifdef DEBUG
CFLAGS = -Wall -Wextra -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
endif

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)

$(SERVER_NAME): $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER_NAME) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)

$(LIBFT_ARCHIVE):
	@make -C libft/ all

$(FT_PRINTF_ARCHIVE):
	@make -C ft_printf/ all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@make -C libft/ clean
	@make -C ft_printf/ clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	
fclean: clean
	rm -f $(LIBFT_ARCHIVE)
	rm -f $(FT_PRINTF_ARCHIVE)
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all fclean clean re
