//ctrol + c で止めると、シグナルが送られる

#include <signal.h>  // シグナルを扱うためのヘッダーファイル
#include <stdio.h>

// シグナルが来たときに動作する関数
void my_signal_handler(int signum) {
    printf("シグナル %d を受け取りました！\n", signum);
}

int main() {
    struct sigaction action;
    action.sa_handler = my_signal_handler; // シグナルを受け取ったときに実行する関数
    sigaction(SIGINT, &action, NULL); // Ctrl + C (SIGINT) の動作を変更

    while (1) {
        // プログラムがずっと動く（止めるには Ctrl + C）
    }

    return 0;
}
