/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:15:41 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/22 17:31:58 by mtsubasa         ###   ########.fr       */
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
		if (info->si_pid > 0)
			kill(info->si_pid, signal);
	}
	(void)context;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		error_handler("Invalid arguments ", "Usage: ./server");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Sigaction error", NULL);
	while (1)
	{
		pause();
		usleep(WAIT_TIME);
	}
	return (0);
}
