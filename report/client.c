/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:16 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/22 16:40:46 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_message(int pid, char c)//送信関数pidは送信先のプロセスID、cは送信する文字
{
	int	bit;//送信する文字のビット数

	bit = 0;
	while (bit < 8)//1bayt(8bit)の文字を送信
	{
		if ((c & (1 << bit)) != 0)//cのbit番目のビットが1の場合
		{
			if (kill(pid, SIGUSR1) == -1)//SIGUSR1を送信(戻り値-1はエラー)
				error_handler("Kill error", "SIGUSR1");
		}
		else//ビットが０の場合
		{
			if (kill(pid, SIGUSR2) == -1)//SIGUSR2を送信
				error_handler("Kill error", "SIGUSR2");
		}
		usleep(WAIT_TIME);//WAIT_TIME分だけ待機//サーバ側のハンドラ処理時間を考慮して送信間隔を調整
		bit++;//次のビットに移動
	}
}

int	main(int ac, char **av)//./client[PID][messege] (av[1]...PID, av[2]...メッセージ)
{
	int	pid;//送信先のプロセスID
	int	index;//メッセージの文字数目

	if (ac != 3)//./client 12412 "helloworld"のような引数であるかを確認
		error_handler("Invalid arguments", "Usage: ./client [PID] [message]");

	if (!bool_atoi(av[1], &pid))//PIDを整数に変換し変数に入力し、正しい数値であるかも確認
		error_handler("Invalid PID", "PID must be a positive integer");

	if (pid <= 0)//PIDが0以下の場合エラー
		error_handler("Invalid PID", "PID must be a positive integer");

	index = 0;
	while (av[2][index])//メッセージを一文字ずつ処理
	{
		send_message(pid, av[2][index]);//メッセージを送信(pid...[./server]のPID, av[message][index]...メッセージの一文字)
		index++;
	}
	send_message(pid, '\n');//メッセージの終わりを示す改行を送信
	return (0);
}
