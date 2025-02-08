/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/12/22 10:21:44 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** このプログラムは、指定されたサーバープロセス（PID）にメッセージを送信するクライアントです。
** メッセージは、各文字がビット単位で分割され、シグナル(SIGUSR1, SIGUSR2)を使用して送信されます。
*/

#include "minitalk_bonus.h"  // ヘッダーのインクルード

/*
** signal_handler:
** サーバーからの応答信号を処理する関数。
** シグナルを受信した際に、特定のメッセージを標準出力に表示します。
**
** 引数:
**   - signal: 受信したシグナル(SIGUSR1またはSIGUSR2)
*/
void	signal_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		write(1, "SIGUSR!!\n", 9);
}

/*
** send_message:
** 指定されたプロセスIDに文字をビット単位で送信します。
** 各ビットに対してSIGUSR1（ビットが1の場合）またはSIGUSR2（ビットが0の場合）を送信します。
**
** 引数:
**   - pid: メッセージを送信する対象プロセスのPID
**   - c: 送信する文字
*/
void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)  // 文字の各ビットを処理
	{
		if ((c & (1 << bit)) != 0)  // 対象ビットが1である場合
		{
			if (kill(pid, SIGUSR1) == -1)  // SIGUSR1を送信
				error_handler("Kill error", "SIGUSR1");
		}
		else  // 対象ビットが0である場合
		{
			if (kill(pid, SIGUSR2) == -1)  // SIGUSR2を送信
				error_handler("Kill error", "SIGUSR2");
		}
		usleep(WAIT_TIME);  // シグナル送信間の待機（サーバーが処理できるようにするため）
		bit++;
	}
}

/*
** main:
** クライアントプログラムのエントリーポイント。
** 引数を解析してメッセージを送信します。
**
** 引数:
**   - ac: コマンドライン引数の数
**   - av: コマンドライン引数の配列
**
** コマンドライン引数:
**   1. ./client: 実行ファイル名
**   2. PID: サーバーのプロセスID
**   3. message: サーバーに送信するメッセージ
*/
int	main(int ac, char **av)
{
	t_sa	sa;         // シグナルアクション構造体
	int		pid;        // サーバーのプロセスID
	int		index;      // メッセージ文字列のインデックス

	// 引数が正しく指定されているか確認
	if (ac != 3)
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");

	// PIDを整数に変換（正の整数であることを確認）
	if (!bool_atoi(av[1], &pid))
		error_handler("Invalid PID", "PID must be a positive integer");
	if (pid <= 0)
		error_handler("Invalid PID", "PID must be a positive integer");

	// シグナルハンドラーを設定
	sa.sa_handler = signal_handler;         // ハンドラー関数を設定
	sigemptyset(&sa.sa_mask);               // マスクを初期化
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1  // SIGUSR1をマスクに追加
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)  // SIGUSR2をマスクに追加
		error_handler("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1  // SIGUSR1のシグナルアクションを設定
		|| sigaction(SIGUSR2, &sa, NULL) == -1)  // SIGUSR2のシグナルアクションを設定
		error_handler("Sigaction error", NULL);
	sa.sa_flags = 0;  // フラグを初期化

	// メッセージを1文字ずつサーバーに送信
	index = 0;
	while (av[2][index])
		send_message(pid, av[2][index++]);  // メッセージ文字を送信
	send_message(pid, '\n');  // メッセージの終端として改行を送信

	// シグナル処理の待機
	usleep(WAIT_TIME);

	return (0);  // 正常終了
}
