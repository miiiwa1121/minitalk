/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2024/12/22 10:23:33 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** このプログラムは、クライアントから送られてくるシグナルを受信し、
** ビットを組み立てて文字として出力するシンプルなサーバーです。
*/

#include "minitalk.h"  // ヘッダーのインクルード

/*
** signal_handler:
** クライアントから送信されたシグナルを処理する関数。
** 受信したシグナル（SIGUSR1またはSIGUSR2）をビットとして組み立て、
** 8ビット（1文字分）受信したらその文字を標準出力に表示します。
**
** 引数:
**   - signal: 受信したシグナル（SIGUSR1またはSIGUSR2）
*/
void	signal_handler(int signal)
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
		write(1, &c, 1);  // 文字を標準出力に表示
		bit = 0;          // ビット位置をリセット
		c = 0;            // 構成中の文字をリセット
	}
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

	// サーバーは引数を受け取らない（引数が指定された場合はエラー）
	if (ac != 1)
		error_handler("Invalid arguments", "Usage: ./server");

	// サーバープロセスIDを表示
	ft_printf("Server PID: %d\n", getpid());

	// シグナルアクションを設定
	sa.sa_handler = signal_handler;  // シグナルハンドラー関数を設定
	sigemptyset(&sa.sa_mask);        // マスクを初期化
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1  // SIGUSR1をマスクに追加
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)  // SIGUSR2をマスクに追加
		error_handler("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1  // SIGUSR1のシグナルアクションを設定
		|| sigaction(SIGUSR2, &sa, NULL) == -1)  // SIGUSR2のシグナルアクションを設定
		error_handler("Sigaction error", NULL);

	// 無限ループでクライアントからのメッセージを待機
	while (1)
	{
		pause();              // シグナルを受信するまで待機
		usleep(WAIT_TIME);    // 処理間の短い待機
	}

	return (0);  // 正常終了（ここには到達しない）
}
