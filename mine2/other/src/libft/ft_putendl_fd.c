/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:36:38 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 00:50:13 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
	{
		return ;
	}
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	write(fd, s, len);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello, world!";
// 	ft_putendl_fd(s, 1);
// 	return (0);
// }
