/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:57:55 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/23 18:26:58 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
// #include <stdlib.h>
// #include <unistd.h>

// void error_handler(const char *msg, const char *details)
// {
//     if (msg)
//         ft_putstr_fd(msg, 2);
//     if (details)
//         ft_putstr_fd(details, 2);
//     ft_putchar_fd('\n', 2);
//     exit(EXIT_FAILURE);
// }

#include <stdlib.h>
#include <unistd.h>

void	error_handler(const char *msg, const char *details)
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);
	if (details)
		ft_putstr_fd((char *)details, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
