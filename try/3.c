//sigemptysetとsigaddsetの重要性

//シグナルセットにSIGTSTPを追加していることで、SIGINTを受信し、シグナルハンドラが実行される間にSIGTSTPが発生しても、５秒間はシグナルハンドラが中断されないことが分かる

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// シグナルハンドラー
void handler(int signo) {
    printf("Received signal: %d\n", signo);
    sleep(5);  // シグナルハンドラー内で 5 秒待つ
    printf("Handler finished for signal: %d\n", signo);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handler;
    sa.sa_flags = 0;

    sigemptyset(&sa.sa_mask);   // マスクを空にする
    sigaddset(&sa.sa_mask, SIGTSTP); // `SIGTSTP (Ctrl+Z)` をブロック

    sigaction(SIGINT, &sa, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}
