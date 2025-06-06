/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:07 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/22 17:30:58 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	ack_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		write(1, "ACK!!SIGUSR!!\n", 14);
}

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_handler("Kill error ", "SIGUSR1");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_handler("Kill error ", "SIGUSR2");
		}
		usleep(WAIT_TIME);
		bit++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;
	int					index;

	if (ac != 3)
		error_handler("Invalid arguments ", "Usage: ./client [PID] [message]");
	if (!bool_atoi(av[1], &pid))
		error_handler("Invalid PID ", "PID must be a positive integer");
	if (pid <= 0)
		error_handler("Invalid PID ", "PID must be a positive integer");
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		error_handler("Sigaddset error", NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error_handler("Sigaction error", NULL);
	index = 0;
	while (av[2][index])
		send_message(pid, av[2][index++]);
	send_message(pid, '\n');
	usleep(WAIT_TIME);
	return (0);
}
