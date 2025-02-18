/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:45:23 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/29 19:06:24 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// void	to_upper(unsigned int index, char *c)
// {
// 	if (*c >= 'a' && *c <= 'z')
// 	{
// 		*c = *c - 32;
// 	}
// }

// void	to_lower(unsigned int index, char *c)
// {
// 	if (*c >= 'A' && *c <= 'Z')
// 	{
// 		*c = *c + 32;
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

// int	main(void)
// {
// 	char	str[] = "HELLO, world!";

// 	printf("Original string: %s\n", str);
// 	ft_striteri(str, to_lower);
// 	printf("Modified string: %s\n", str);
// 	return (0);
// }
