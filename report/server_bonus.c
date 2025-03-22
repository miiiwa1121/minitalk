/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:22:14 by jtakahas          #+#    #+#             */
/*   Updated: 2025/03/23 01:42:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
		if (info->si_pid > 0) // NULL チェック
			kill(info->si_pid, signal);// クライアントにACK（確認応答）を送信
		//（SIGUSR1 または SIGUSR2）を返す。
		//si_pid は、siginfo_t 構造体のメンバで、シグナルを送信したプロセスのプロセス ID (PID) を表します。
		//`sa_flags`に`SA_SIGINFO`を設定すると、`sigaction`でこの情報を取得できます。
		//「->」はC言語におけるポインタを使った構造体メンバーへのアクセスを表す記法
		//通常の構造体変数の場合はドット記法（.）を使いますが、ポインタの場合は -> を使います。
		//info_ptr->si_pid は実際には (*info_ptr).si_pid と同じ意味ですが、コードの可読性を考慮して -> を使います。
		
		// kill(info->si_pid, signal);
	}
	(void)context;//未使用の引数を無視
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		error_handler("Invalid arguments", "Usage: ./server");

	ft_printf("Server PID: %d\n", getpid());

	sa.sa_flags = SA_SIGINFO;//sa_flags に SA_SIGINFO を設定すると、sa_sigactionがsa_handlerの代わりに呼ばれる。

	sa.sa_sigaction = signal_handler;//より詳細な設定

	sigemptyset(&sa.sa_mask);

	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1 || sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Sigaddset error", NULL);

	if (sigaction(SIGUSR1, &sa, NULL) == -1	|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Sigaction error", NULL);

	while (1)
	{
		pause();
		usleep(WAIT_TIME);
	}
	return (0);
}
