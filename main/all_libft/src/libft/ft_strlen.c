/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:25:32 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/16 16:23:36 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int len;
// 	char s[] = "today";

// 	len = ft_strlen(s);
// 	printf("\"%s\" は %d 文字\n", s, len);
// 	return (0);
// }
