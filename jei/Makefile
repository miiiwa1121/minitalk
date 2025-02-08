# ======================================
# 基本情報
# ======================================

# プロジェクトの名前
NAME = minitalk
BONUS_NAME = minitalk_bonus

# 実行ファイル名（サーバーとクライアント）
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# libftライブラリの設定
LIBFT_NAME = libft               # libftライブラリの名前
LIBFT_DIR = libft/               # libftのディレクトリパス

# ヘッダーファイルの設定
INCLUDE_DIR = include/           # ヘッダーファイルディレクトリ
INCLUDE = -I $(INCLUDE_DIR)      # インクルードオプション
LIBFT_INCLUDE = -I $(LIBFT_DIR)$(INCLUDE_DIR)  # libft用のインクルードディレクトリ

# ソースコードとオブジェクトファイルのディレクトリ
SRC_DIR = src/                   # ソースコードのディレクトリ
OBJ_DIR = .obj/                  # オブジェクトファイルのディレクトリ

# コンパイラとその設定
CC = cc                          # 使用するコンパイラ
CFLAGS = -Wall -Wextra -Werror   # コンパイルオプション

# アーカイブ用コマンドと削除コマンド
AR = ar                          # アーカイブコマンド
ARFLAGS = rcs                    # アーカイブオプション
RM = rm -rf                      # 削除コマンド

# コード規約チェックツール
NORM = norminette

# ======================================
# 必須部分（mandatory part）
# ======================================

# サーバーとクライアントのソースファイル
SRC_FILES = server.c client.c
# ソースファイルの完全パスを生成
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# オブジェクトファイル名を作成
OJB_FILES = $(SRC_FILES:%.c=%.o)
# オブジェクトファイルの完全パスを生成
OBJS = $(addprefix $(OBJ_DIR), $(OJB_FILES))

# サーバーとクライアント個別のオブジェクトファイル
SERVER_OBJS = $(addprefix $(OBJ_DIR), server.o)
CLIENT_OBJS = $(addprefix $(OBJ_DIR), client.o)

# ======================================
# ボーナス部分（bonus part）
# ======================================

# ボーナス用ソースファイル
SRC_FILES_BONUS = server_bonus.c client_bonus.c
# ソースファイルの完全パスを生成
SRCS_BONUS = $(addprefix $(SRC_DIR), $(SRC_FILES_BONUS))
# オブジェクトファイル名を作成
OJB_FILES_BONUS = $(SRC_FILES_BONUS:%.c=%.o)
# オブジェクトファイルの完全パスを生成
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(OJB_FILES_BONUS))

# サーバーボーナスとクライアントボーナス個別のオブジェクトファイル
SERVER_BONUS_OBJS = $(addprefix $(OBJ_DIR), server_bonus.o)
CLIENT_BONUS_OBJS = $(addprefix $(OBJ_DIR), client_bonus.o)

# ======================================
# カラーログ設定
# ======================================

# ANSIエスケープシーケンスでログに色を付ける
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

# デフォルトターゲット（すべてをビルド）
all: $(OBJ_DIR) $(OBJS) $(SERVER) $(CLIENT)

# ボーナス部分のビルド
bonus: $(OBJ_DIR) $(OBJS_BONUS) $(SERVER_BONUS) $(CLIENT_BONUS)

# サーバーのビルド
$(SERVER): $(OBJ_DIR) $(SERVER_OBJS)
	@echo $(Y) "$(NAME) src files successfully compiled\n" $(X)
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)  # libftライブラリのビルド
	@echo $(B) "<-- Out of $(LIBFT_DIR)\n" $(X)
	@echo $(B) "$(SERVER) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER)  # 実行ファイル作成
	@echo $(G) "!! $(SERVER) created !!\n" $(X)

# クライアントのビルド
$(CLIENT): $(OBJ_DIR) $(CLIENT_OBJS)
	@echo $(B) "$(CLIENT) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT)
	@echo $(G) "!! $(CLIENT) created !!" $(X)

# 必要なディレクトリを作成
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

# ソースファイルからオブジェクトファイルを生成
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $(Y) "Compiling $<" $(X)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@
	@printf $(UP)$(CUT)

# サーバーボーナスのビルド
$(SERVER_BONUS): $(OBJ_DIR) $(SERVER_BONUS_OBJS)
	@echo $(Y) "$(BONUS_NAME) srs files successfully compiled\n" $(X)
	@echo $(B) "--> Into $(LIBFT_DIR)" $(X)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo $(B) "<-- Out of $(LIBFT_DIR)\n" $(X)
	@echo $(B) "$(SERVER_BONUS) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(SERVER_BONUS)
	@echo $(G) "!! $(SERVER_BONUS) created !!\n" $(X)

# クライアントボーナスのビルド
$(CLIENT_BONUS): $(OBJ_DIR) $(CLIENT_BONUS_OBJS)
	@echo $(B) "$(CLIENT_BONUS) creating" $(X)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(CLIENT_BONUS)
	@echo $(G) "!! $(CLIENT_BONUS) created !!" $(X)

# ======================================
# クリーンアップ
# ======================================

# 中間ファイルを削除
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo $(R) "$(NAME) cleaned\n" $(X)

# 生成物を完全に削除
fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo $(R) "$(NAME) fcleaned\n" $(X)

# 再構築
re: fclean all

# ボーナス再構築
rebonus: fclean bonus

# ======================================
# コーディング規約チェック
# ======================================

# コード規約のチェック
norm:
	@echo $(R) "<<< $(NAME) error count >>>" $(X)
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error | grep -v Error! | wc -l
	@norminette $(SRC_DIR) $(INCLUDE_DIR) | grep Error || true
	@$(MAKE) -C $(LIBFT_DIR) norm

# ======================================
# 必須ターゲット定義
# ======================================
.PHONY: all clean fclean re norm
