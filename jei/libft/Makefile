# ======================================
# Makefile for the libft library
# ======================================

# ライブラリ名
NAME		= libft

# ヘッダーファイルのディレクトリとその指定
INCLUDE_DIR	= include/
INCLUDE		= -I $(INCLUDE_DIR)

# ソースコードとオブジェクトファイルのディレクトリ
SRC_DIR		= src/
OBJ_DIR		= .obj/

# 使用するコンパイラとそのオプション
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# アーカイブ作成用コマンドとオプション
AR			= ar
ARFLAGS		= rcs

# 削除コマンド
RM			= rm -rf

# コード規約チェックツール
NORM		= norminette

# ======================================
# サブディレクトリとそのソースファイル
# ======================================

# 標準ライブラリ関数
LIBFT_DIR	= std_libft/
STDLIB_DIR	= stdlib/
STDLIB_SRC	=	ft_atoi.c\
				ft_calloc.c\
				ft_itoa.c\
				ft_abs.c\
				bool_atoi.c

# 文字タイプ判定関数
CTYPE_DIR	= ctype/
CTYPE_SRC	=	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_isspace.c\
				ft_tolower.c\
				ft_toupper.c

# メモリ操作関数
MEM_DIR		= mem/
MEM_SRC		=	ft_bzero.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c

# 文字列操作関数
STR_DIR		= str/
STR_SRC		=	ft_strjoin.c\
				ft_strnstr.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strmapi.c\
				ft_strlen.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_strncmp.c\
				ft_strdup.c\
				ft_split.c\
				ft_striteri.c\
				put_message.c

# ファイルディスクリプタ操作関数
FD_DIR		= fd/
FD_SRC		=	ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c

# リンクリスト操作関数
LST_DIR		= lst/
LST_SRC		=	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

# エラーハンドリング関数
ERROR_DIR	= error/
ERROR_SRC	=	error.c

# ソースファイルをディレクトリパス付きでリスト化
LIBFT_SRC	+= $(addprefix $(STDLIB_DIR), $(STDLIB_SRC))
LIBFT_SRC	+= $(addprefix $(CTYPE_DIR), $(CTYPE_SRC))
LIBFT_SRC	+= $(addprefix $(MEM_DIR), $(MEM_SRC))
LIBFT_SRC	+= $(addprefix $(STR_DIR), $(STR_SRC))
LIBFT_SRC	+= $(addprefix $(FD_DIR), $(FD_SRC))
LIBFT_SRC	+= $(addprefix $(LST_DIR), $(LST_SRC))
LIBFT_SRC	+= $(addprefix $(ERROR_DIR), $(ERROR_SRC))

# ======================================
# 他のライブラリ（例: GNL, printf）
# ======================================

# get_next_line ライブラリ
GNL_DIR		= gnl/
GNL_SRC		= get_next_line.c        get_next_line_utils.c

# ft_printf ライブラリ
FTPRINTF_DIR	= ft_printf/
FTPRINTF_SRC	= ft_printf.c      output.c         print_hex.c      print_ptr.c      unsigned_itoa.c

# 全ソースファイルをディレクトリパス付きでリスト化
SRC_FILES 	+= $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))
SRC_FILES 	+= $(addprefix $(GNL_DIR), $(GNL_SRC))
SRC_FILES 	+= $(addprefix $(FTPRINTF_DIR), $(FTPRINTF_SRC))

# オブジェクトファイルのリストを生成
OBJ_FILES 	= $(SRC_FILES:%.c=%.o)

# 完全なソースファイルとオブジェクトファイルのパス
SRCS 		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS 		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# ======================================
# カラーログの設定
# ======================================

# ANSIエスケープシーケンスでログに色付け
Y 			= "\033[33m"  # 黄色
R 			= "\033[31m"  # 赤
G 			= "\033[32m"  # 緑
B 			= "\033[34m"  # 青
X 			= "\033[0m"   # リセット
UP 			= "\033[A"    # カーソルを1行上に移動
CUT 		= "\033[K"    # カーソルから行末を削除

# ======================================
# ターゲットとルール
# ======================================

# デフォルトターゲット
all: ${NAME}

# ライブラリを作成
${NAME}: $(OBJ_DIR) ${OBJS}
	@echo $(Y) "$(NAME) successfully compiled\n" $(X)
	@echo $(B) "$(NAME) archiving\n" $(X)
	@printf $(UP)$(CUT)
	@printf $(UP)$(CUT)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo $(G) "!! $(NAME) created !!" $(X)

# ソースコードをコンパイルしてオブジェクトファイルを生成
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(Y) "Compiling $< " $(X)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf $(UP)$(CUT)

# 必要なディレクトリを作成
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(STDLIB_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(CTYPE_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(MEM_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(STR_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(FD_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(LST_DIR)
	@mkdir $(OBJ_DIR)$(LIBFT_DIR)$(ERROR_DIR)
	@mkdir $(OBJ_DIR)$(GNL_DIR)
	@mkdir $(OBJ_DIR)$(FTPRINTF_DIR)

# ======================================
# クリーンアップルール
# ======================================

# 中間ファイルを削除
clean:
	@${RM} ${OBJ_DIR}
	@echo $(R) "$(NAME) cleaned\n" $(X)

# 生成物を完全に削除
fclean:
	@${RM} ${OBJ_DIR}
	@${RM} ${NAME}
	@echo $(R) "$(NAME) fcleaned\n" $(X)

# 再構築
re: fclean all

# ======================================
# コーディング規約チェック
# ======================================

norm:
	@echo $(R) "<<< libft error count >>>" $(X)
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error | grep -v Error! | wc -l
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error || true

# ======================================
# 必須ターゲット定義
# ======================================
.PHONY : all clean fclean re norm
