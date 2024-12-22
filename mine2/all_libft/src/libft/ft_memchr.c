/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:24:25 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/22 23:51:59 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = s;
	uc = c;
	while (n--)
	{
		if (*p == uc)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str = "Hello, world!";
// 	char		search_char;
// 	void		*result;

// 	search_char = 'w';
// 	result = ft_memchr(str, search_char, 5);
// 	if (result != NULL)
// 	{
// 		printf("'%c': %ld\n", search_char, (char *)result - str);
// 	}
// 	else
// 	{
// 		printf("'%c'\n", search_char);
// 	}
// 	return (0);
// }
