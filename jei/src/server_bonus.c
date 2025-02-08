/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2024/12/22 10:22:25 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** このプログラムは、クライアントから送られてくるシグナルを受信し、
** ビットを組み立てて文字として表示するサーバーです。
*/

#include "minitalk_bonus.h"  // ヘッダーのインクルード

/*
** signal_handler:
** クライアントからのシグナルを処理する関数。
** 1ビットずつ文字を構成し、8ビット分受信したら文字を表示します。
** また、シグナル送信元のクライアントに応答信号を返します。
**
** 引数:
**   - signal: 受信したシグナル（SIGUSR1またはSIGUSR2）
**   - info: 送信元プロセスの情報を含む構造体（`si_pid`など）
**   - context: 使用しない（POSIX仕様のための引数）
*/
void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;  // 現在処理中のビット位置を記録
	static int	c;    // 現在構成中の文字

	// SIGUSR1を受信した場合、対応するビットを1に設定
	if (signal == SIGUSR1)
		c |= (1 << bit);

	bit++;  // 次のビット位置に移動

	// 8ビット（1文字分）受信した場合
	if (bit == 8)
	{
		write(1, &c, 1);  // 文字を出力
		bit = 0;          // ビット位置をリセット
		c = 0;            // 文字の初期化
		kill(info->si_pid, signal);  // クライアントに応答信号を送信
	}
	(void)context;  // 使用しない引数を無視
}

/*
** main:
** サーバープログラムのエントリーポイント。
** シグナルハンドラーを設定し、クライアントからのメッセージを待機します。
**
** 引数:
**   - ac: コマンドライン引数の数
**   - av: コマンドライン引数の配列
**
** コマンドライン引数:
**   1. ./server: 実行ファイル名（引数は不要）
*/
int	main(int ac, char **av)
{
	t_sa	sa;  // シグナルアクション構造体

	(void)av;  // コマンドライン引数を無視（サーバーには不要）
	if (ac != 1)  // 引数が指定された場合、エラーを出力
		error_handler("Invalid arguments", "Usage: ./server");

	// サーバーのPIDを表示
	ft_printf("Server PID: %d\n", getpid());

	// シグナルアクションを設定
	sa.sa_sigaction = signal_handler;  // シグナルハンドラー関数を設定
	sigemptyset(&sa.sa_mask);          // マスクを初期化
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1  // SIGUSR1をマスクに追加
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)  // SIGUSR2をマスクに追加
		error_handler("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1  // SIGUSR1のシグナルアクションを設定
		|| sigaction(SIGUSR2, &sa, NULL) == -1)  // SIGUSR2のシグナルアクションを設定
		error_handler("Sigaction error", NULL);
	sa.sa_flags = 0;  // フラグを初期化

	// シグナルを待機（無限ループ）
	while (1)
	{
		pause();              // シグナルを受け取るまで待機
		usleep(WAIT_TIME);    // 処理の間隔を確保
	}

	return (0);  // 正常終了（ここには到達しない）
}
