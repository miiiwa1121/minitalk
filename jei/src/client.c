/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:49:01 by jtakahas          #+#    #+#             */
/*   Updated: 2024/12/22 10:23:01 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** このプログラムは、指定されたサーバープロセス（PID）にメッセージを送信するクライアントです。
** メッセージは各文字がビット単位に分割され、シグナル(SIGUSR1, SIGUSR2)を使って送信されます。
*/

#include "minitalk.h"  // ヘッダーファイルのインクルード

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
	while (bit < 8)  // 文字の8ビットを処理
	{
		if ((c & (1 << bit)) != 0)  // 対象ビットが1の場合
		{
			if (kill(pid, SIGUSR1) == -1)  // SIGUSR1を送信
				error_handler("Kill error", "SIGUSR1");
		}
		else  // 対象ビットが0の場合
		{
			if (kill(pid, SIGUSR2) == -1)  // SIGUSR2を送信
				error_handler("Kill error", "SIGUSR2");
		}
		usleep(WAIT_TIME);  // サーバーが処理できるように待機
		bit++;
	}
}

/*
** main:
** クライアントプログラムのエントリーポイント。
** 引数を解析し、指定されたサーバープロセスにメッセージを送信します。
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
	int	pid;    // サーバープロセスのPID
	int	index;  // メッセージ文字列のインデックス

	// 引数の数をチェック（3つ必要: ./client, PID, message）
	if (ac != 3)
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");

	// PIDを正の整数に変換して取得
	if (!bool_atoi(av[1], &pid))
		error_handler("Invalid PID", "PID must be a positive integer");
	if (pid <= 0)
		error_handler("Invalid PID", "PID must be a positive integer");

	// メッセージを1文字ずつ送信
	index = 0;
	while (av[2][index])
	{
		send_message(pid, av[2][index]);  // 現在の文字を送信
		index++;
	}

	// メッセージの終端を通知（改行文字を送信）
	send_message(pid, '\n');
	return (0);  // 正常終了
}
