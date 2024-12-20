/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:46:42 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/17 17:46:46 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	digits_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	number_sequence(int n, char *str, size_t len)
{
	unsigned int	num;

	if (n < 0)
	{
		num = -n;
	}
	else
	{
		num = n;
	}
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*str;

	digits = digits_len(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
	{
		return (NULL);
	}
	number_sequence(n, str, digits);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		num;
// 	char	*str;

// 	num = -0;
// 	str = ft_itoa(num);
// 	if (str)
// 	{
// 		printf("Integer: %d, String: %s\n", num, str);
// 		free(str);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }
