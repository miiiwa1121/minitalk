# # ========================================================
# # Makefile for minitalk: Builds server, client and bonuses
# # ========================================================

# # プロジェクト名
# NAME = minitalk
# BONUS_NAME = minitalk_bonus

# # ライブラリ情報
# LIBFT_DIR = all_libft
# LIBFT_NAME = $(LIBFT_DIR)/all_libft.a
# LIBFT_INCLUDE = -I $(LIBFT_DIR)/include

# # ディレクトリ
# INCLUDE_DIR = include
# SRC_DIR = src
# OBJ_DIR = .obj

# # コンパイラ設定
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# INCLUDE = -I $(INCLUDE_DIR) $(LIBFT_INCLUDE)

# # ソースファイル
# CLIENT_SRC = $(SRC_DIR)/client.c
# SERVER_SRC = $(SRC_DIR)/server.c
# CLIENT_BONUS_SRC = $(SRC_DIR)/client_bonus.c
# SERVER_BONUS_SRC = $(SRC_DIR)/server_bonus.c

# # オブジェクトファイル
# CLIENT_OBJ = $(OBJ_DIR)/client.o
# SERVER_OBJ = $(OBJ_DIR)/server.o
# CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o
# SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o

# # カラー設定
# Y = "\033[33m"
# R = "\033[31m"
# G = "\033[32m"
# X = "\033[0m"

# # ========================================================
# # ルール
# # ========================================================

# all: $(LIBFT_NAME) $(SERVER_OBJ) $(CLIENT_OBJ)
# 	@echo $(Y) "Building server..." $(X)
# 	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_NAME) -o server
# 	@echo $(G) "server created!" $(X)
# 	@echo $(Y) "Building client..." $(X)
# 	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_NAME) -o client
# 	@echo $(G) "client created!" $(X)

# bonus: $(LIBFT_NAME) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
# 	@echo $(Y) "Building server_bonus..." $(X)
# 	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT_NAME) -o server_bonus
# 	@echo $(G) "server_bonus created!" $(X)
# 	@echo $(Y) "Building client_bonus..." $(X)
# 	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT_NAME) -o client_bonus
# 	@echo $(G) "client_bonus created!" $(X)

# # ライブラリをビルド
# $(LIBFT_NAME):
# 	@echo $(Y) "Building all_libft..." $(X)
# 	@$(MAKE) -C $(LIBFT_DIR)
# 	@echo $(G) "all_libft built!" $(X)

# # オブジェクトファイルをビルド
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
# 	@mkdir -p $(OBJ_DIR)
# 	@echo $(Y) "Compiling $<..." $(X)
# 	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# # クリーンアップ
# clean:
# 	@echo $(R) "Cleaning object files..." $(X)
# 	@rm -rf $(OBJ_DIR)
# 	@$(MAKE) -C $(LIBFT_DIR) clean

# fclean: clean
# 	@echo $(R) "Cleaning executables and library..." $(X)
# 	@rm -f server client server_bonus client_bonus
# 	@$(MAKE) -C $(LIBFT_DIR) fclean

# # 再ビルド
# re: fclean all

# # ボーナス再ビルド
# rebonus: fclean bonus

# # コーディング規約チェック
# norm:
# 	@norminette $(SRC_DIR) $(INCLUDE_DIR)
# 	@$(MAKE) -C $(LIBFT_DIR) norm

# .PHONY: all bonus clean fclean re rebonus norm

# ============================
# 修正版 Makefile
# ============================

NAME = minitalk
LIBFT_NAME = all_libft/all_libft.a
LIBFT_INCLUDE = -I all_libft/include

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = .obj

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(INCLUDE_DIR) $(LIBFT_INCLUDE)

SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_BONUS_SRC = $(SRC_DIR)/server_bonus.c
CLIENT_BONUS_SRC = $(SRC_DIR)/client_bonus.c

SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_BONUS_OBJ = $(OBJ_DIR)/server_bonus.o
CLIENT_BONUS_OBJ = $(OBJ_DIR)/client_bonus.o

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

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(G) "Compiled $<" $(X)

$(LIBFT_NAME):
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

.PHONY: all clean fclean re bonus server client
