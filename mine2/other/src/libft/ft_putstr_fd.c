/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:40:49 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/02 09:38:41 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return ;
	len = ft_strlen((const char *)s);
	write(fd, s, len);
}

// int main(void)
// {
//     char *s;

//     s = "Hello, world!";
//     ft_putstr_fd(s, 1);
//     return (0);
// }
