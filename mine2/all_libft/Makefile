# ========================================================
# Makefile for all_libft: Combines libft, ft_printf, gnl
# ========================================================

# ターゲットライブラリ名
NAME = all_libft.a

# ディレクトリ
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = .obj

# 各サブディレクトリ
FT_PRINTF_DIR = $(SRC_DIR)/ft_printf
GNL_DIR = $(SRC_DIR)/gnl
LIBFT_DIR = $(SRC_DIR)/libft

# コンパイラとフラグ
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(INCLUDE_DIR)

# ソースファイルのリスト
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_print_char.c \
                $(FT_PRINTF_DIR)/ft_print_hex.c \
                $(FT_PRINTF_DIR)/ft_print_integer.c \
                $(FT_PRINTF_DIR)/ft_print_pointer.c \
                $(FT_PRINTF_DIR)/ft_print_string.c \
                $(FT_PRINTF_DIR)/ft_print_unsigned.c \
                $(FT_PRINTF_DIR)/ft_printf.c

GNL_SRC = $(GNL_DIR)/get_next_line_bonus.c \
          $(GNL_DIR)/get_next_line_utils_bonus.c

LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c \
            $(LIBFT_DIR)/ft_bzero.c \
            $(LIBFT_DIR)/ft_calloc.c \
            $(LIBFT_DIR)/ft_isalnum.c \
            $(LIBFT_DIR)/ft_isalpha.c \
            $(LIBFT_DIR)/ft_isascii.c \
            $(LIBFT_DIR)/ft_isdigit.c \
            $(LIBFT_DIR)/ft_isprint.c \
            $(LIBFT_DIR)/ft_itoa.c \
            $(LIBFT_DIR)/ft_lstadd_back.c \
            $(LIBFT_DIR)/ft_lstadd_front.c \
            $(LIBFT_DIR)/ft_lstclear.c \
            $(LIBFT_DIR)/ft_lstdelone.c \
            $(LIBFT_DIR)/ft_lstiter.c \
            $(LIBFT_DIR)/ft_lstlast.c \
            $(LIBFT_DIR)/ft_lstmap.c \
            $(LIBFT_DIR)/ft_lstnew.c \
            $(LIBFT_DIR)/ft_lstsize.c \
            $(LIBFT_DIR)/ft_memchr.c \
            $(LIBFT_DIR)/ft_memcmp.c \
            $(LIBFT_DIR)/ft_memcpy.c \
            $(LIBFT_DIR)/ft_memmove.c \
            $(LIBFT_DIR)/ft_memset.c \
            $(LIBFT_DIR)/ft_putchar_fd.c \
            $(LIBFT_DIR)/ft_putendl_fd.c \
            $(LIBFT_DIR)/ft_putnbr_fd.c \
            $(LIBFT_DIR)/ft_putstr_fd.c \
            $(LIBFT_DIR)/ft_split.c \
            $(LIBFT_DIR)/ft_strchr.c \
            $(LIBFT_DIR)/ft_strdup.c \
            $(LIBFT_DIR)/ft_striteri.c \
            $(LIBFT_DIR)/ft_strjoin.c \
            $(LIBFT_DIR)/ft_strlcat.c \
            $(LIBFT_DIR)/ft_strlcpy.c \
            $(LIBFT_DIR)/ft_strlen.c \
            $(LIBFT_DIR)/ft_strmapi.c \
            $(LIBFT_DIR)/ft_strncmp.c \
            $(LIBFT_DIR)/ft_strnstr.c \
            $(LIBFT_DIR)/ft_strrchr.c \
            $(LIBFT_DIR)/ft_strtrim.c \
            $(LIBFT_DIR)/ft_substr.c \
            $(LIBFT_DIR)/ft_toupper.c \
            $(LIBFT_DIR)/error_handler.c \
            $(LIBFT_DIR)/bool_atoi.c \
            $(LIBFT_DIR)/ft_isspace.c

# すべてのソースファイルとオブジェクトファイル
SRC_FILES = $(FT_PRINTF_SRC) $(GNL_SRC) $(LIBFT_SRC)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# カラーコード
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
X = "\033[0m"

# ========================================================
# ルール
# ========================================================

# デフォルトのターゲット
all: $(NAME)

# ライブラリを作成
$(NAME): $(OBJ_FILES)
	@echo $(Y) "Archiving $(NAME)..." $(X)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo $(G) "$(NAME) created!" $(X)

# オブジェクトファイルを生成
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo $(Y) "Compiling $<..." $(X)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# クリーンアップ
clean:
	@rm -rf $(OBJ_DIR)
	@echo $(R) "Object files removed." $(X)

# フルクリーンアップ
fclean: clean
	@rm -f $(NAME)
	@echo $(R) "$(NAME) removed." $(X)

# 再ビルド
re: fclean all

# コーディング規約のチェック
norm:
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep -v Norme | grep Error || true

.PHONY: all clean fclean re norm
