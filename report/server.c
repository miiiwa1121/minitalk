/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:31 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/02/21 10:01:09 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signal)
{
	static int	bit;//処理中のビットの位置を保持
	static int	c;//受信中の文字のビット情報を保持

	if (signal == SIGUSR1)//ビットが１の場合
		c |= (1 << bit);
	bit++;
	if (bit == 8)//８ビット分の処理が終わったら
	{
		write(1, &c, 1);//cに蓄積した８ビット分にバイナリを文字として出力
		bit = 0;
		c = 0;//リセット
	}
}

int	main(int ac, char **av)
{
	t_sa	sa;//シグナル処理の設定を保持する構造体

//このプログラムはサーバー側のプログラムであるため、引数は不要
	(void)av;//未使用の引数を無視
	if (ac != 1)
		error_handler("Invalid arguments", "Usage: ./server");
//サーバーのプロセスIDを表示
	ft_printf("Server PID: %d\n", getpid());
//シグナルハンドラの設定	
	sa.sa_handler = signal_handler;//シグナルを受信した際に呼び出される関数ポインタに、
	// 実行する関数を設定
//シグナル処理の設定（シグナルマスク）を初期化	
	sigemptyset(&sa.sa_mask);
//SIGUSR1とSIGUSR2をブロックする	
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1//シグナルマスクにSIGUSR1とSIGUSR2を追加
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Sigaddset error", NULL);
//シグナル処理の設定を有効にする
	if (sigaction(SIGUSR1, &sa, NULL) == -1//SIGUSR1とSIGUSR2のシグナル処理を設定
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Sigaction error", NULL);
//シグナル処理の設定を初期化	
	sa.sa_flags = 0;
//無限ループ
	while (1)
	{
		pause();//シグナルを受信するまで待機
		usleep(WAIT_TIME);//WAIT_TIME分だけ待機
	}
	return (0);
}
