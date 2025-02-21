# ============================
# Makefile
# ============================

# プロジェクト名
NAME = minitalk

# all_libftライブラリの情報
LIBFT_NAME = all_libft/all_libft.a
LIBFT_INCLUDE = -I all_libft/include

# ディレクトリ構成
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = .obj

# コンパイラ設定
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(INCLUDE_DIR) $(LIBFT_INCLUDE)

# ソースファイル
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_BONUS_SRC = $(SRC_DIR)/server_bonus.c
CLIENT_BONUS_SRC = $(SRC_DIR)/client_bonus.c

# オブジェクトファイル
SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o
CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o

# 色コード
G = "\033[32m"  # 緑色
R = "\033[31m"  # 赤色
X = "\033[0m"   # リセット

# ========================================================
# ターゲット定義
# ========================================================

all: $(LIBFT_NAME) server client 

server: $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_NAME) -o server
	@echo $(G) "server created!" $(X)

client: $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_NAME) -o client
	@echo $(G) "client created!" $(X)

bonus: $(LIBFT_NAME) server_bonus client_bonus

server_bonus: $(SERVER_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT_NAME) -o server_bonus
	@echo $(G) "server_bonus created!" $(X)

client_bonus: $(CLIENT_BONUS_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT_NAME) -o client_bonus
	@echo $(G) "client_bonus created!" $(X)

# ========================================================
# ビルドルール
# ========================================================

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(G) "Compiled $< to $@" $(X)

$(LIBFT_NAME):
	@echo $(G) "Building all_libft..." $(X)
	@$(MAKE) -C all_libft

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C all_libft clean
	@echo $(R) "Object files removed." $(X)

fclean: clean
	@rm -f server client server_bonus client_bonus
	@$(MAKE) -C all_libft fclean
	@echo $(R) "Executables and library removed." $(X)

re: fclean all

.PHONY: all clean fclean re bonus
