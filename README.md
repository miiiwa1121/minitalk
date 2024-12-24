# minitalk
＜実行＞
allのビルド:
make

ボーナスのビルド:
make bonus

中間ファイルの削除:
make clean

完全なクリーンアップ:
make fclean

再ビルド:
make re

--------------------------------------------------------

＜コマンド＞
kill:指定されたプロセスにシグナルを送るシステムコール
error_handler:プログラム内でエラーが発生した場合に、その原因を処理・表示するための関数
usleep:指定した時間（マイクロ秒単位）だけプログラムの実行を停止
getpid:プロセスID（PID）を取得するシステムコール
sigemptyset: シグナルマスク（シグナルの集合）を空に初期化
sigaddset:シグナルマスクに特定のシグナルを追加
sigaction:特定のシグナルを受け取ったときの処理を設定
pause:シグナルが到達するまでプログラムを停止（待機）
PID:OSが各プロセスを一意に識別するために割り当てる番号

--------------------------------------------------------

＜メモ＞
シグナル:UNIXやLinux環境でプロセス間通信やシステムからプロセスへの通知を行うための機構。シグナルはソフトウェア的な割り込みとして動作し、特定のイベントをプロセスに通知する
システムコール:ユーザープログラムがOSのカーネル機能を利用するためのインターフェース。ファイル操作、プロセス管理、メモリ管理、ネットワーク通信など低レベルな操作を実現
シグナルマスク:

--------------------------------------------------------

＜疑問＞
client
if ((c & (1 << bit)) != 0):

server
c |= (1 << bit);


git add .
git commit -m "ok"
git push