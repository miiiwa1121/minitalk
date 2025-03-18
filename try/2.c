//複数のシグナルをキャッチし出力するプログラム

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// シグナルハンドラ関数
void signal_handler(int signum) {
    printf("シグナル %d を受け取りました！\n", signum);
}

int main() {
    struct sigaction action;
    action.sa_handler = signal_handler; // ハンドラ関数を設定
    sigemptyset(&action.sa_mask); // 他のシグナルをブロックしない
    action.sa_flags = 0; // 特別なフラグなし

    // いくつかのシグナルをキャッチするように設定
    sigaction(SIGINT, &action, NULL);   // Ctrl + C (SIGINT)
    sigaction(SIGTERM, &action, NULL);  // kill コマンドなど (SIGTERM)
    sigaction(SIGHUP, &action, NULL);   // ターミナルのハングアップ (SIGHUP)
    sigaction(SIGUSR1, &action, NULL);  // ユーザー定義シグナル1 (SIGUSR1)
    sigaction(SIGUSR2, &action, NULL);  // ユーザー定義シグナル2 (SIGUSR2)

    printf("シグナルを待っています... (PID: %d)\n", getpid());

    while (1) {
        pause(); // シグナルを待つ
    }

    return 0;
}