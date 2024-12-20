NAME		= minitalk
CLIENT		= client
SERVER		= server
BONUS_CLIENT	= client_bonus
BONUS_SERVER	= server_bonus

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

INCS_DIR	= include/
SRCS_DIR	= src/
OTHER_DIR	= other/

SRCS_CLIENT	= $(SRCS_DIR)client.c
SRCS_SERVER	= $(SRCS_DIR)server.c
BONUS_SRCS_CLIENT= $(SRCS_DIR)client_bonus.c
BONUS_SRCS_SERVER= $(SRCS_DIR)server_bonus.c

OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
BONUS_OBJS_CLIENT= $(BONUS_SRCS_CLIENT:.c=.o)
BONUS_OBJS_SERVER= $(BONUS_SRCS_SERVER:.c=.o)

OTHER_LIB	= $(OTHER_DIR)libother.a

all: $(OTHER_LIB) $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ $(OTHER_LIB)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^ $(OTHER_LIB)

bonus: $(OTHER_LIB) $(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT): $(BONUS_OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ $(OTHER_LIB)

$(BONUS_SERVER): $(BONUS_OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^ $(OTHER_LIB)

$(OTHER_LIB):
	make -C $(OTHER_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	make -C $(OTHER_DIR) clean
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(BONUS_OBJS_CLIENT) $(BONUS_OBJS_SERVER)

fclean: clean
	make -C $(OTHER_DIR) fclean
	$(RM) $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re: fclean all

.PHONY: all bonus clean fclean re