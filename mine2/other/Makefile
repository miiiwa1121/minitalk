NAME		= libother.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

INCS_DIR	= include/
SRCS_DIR	= src/

SRCS		= $(wildcard $(SRCS_DIR)ft_printf/*.c) \
		  $(wildcard $(SRCS_DIR)gnl/*.c) \
		  $(wildcard $(SRCS_DIR)libft/*.c)

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re