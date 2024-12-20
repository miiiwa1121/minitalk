/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:46:53 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/30 12:32:45 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long	checknum(long n, const char *s, int sign)
{
	if (sign == 1 && (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && *s
				- '0' >= LONG_MAX % 10)))
		return (LONG_MAX);
	else if (sign == -1 && (-n < LONG_MIN / 10 || (-n == LONG_MIN / 10 && -(*s
					- '0') <= LONG_MIN % 10)))
		return (LONG_MIN);
	else
	{
		n *= 10;
		n += *s++ - '0';
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while ((*str >= '\011' && *str <= '\015') || *str == '\040')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*str))
	{
		num = checknum(num, str, sign);
		str++;
	}
	return (num * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test 1: \"%s\" -> %d\n", "+-54", ft_atoi("+-54"));
// 		// Expected: 0
// 	printf("Test 2: \"%s\" -> %d\n", "-+48", ft_atoi("-+48"));
// 		// Expected: 0
// 	printf("Test 3: \"%s\" -> %d\n", "   -123", ft_atoi("   -123"));
// 		// Expected: -123
// 	printf("Test 4: \"%s\" -> %d\n", "+42", ft_atoi("+42"));
// 		// Expected: 42
// 	printf("Test 5: \"%s\" -> %d\n", "   +007", ft_atoi("   +007"));
// 		// Expected: 7
// 	printf("Test 6: \"%s\" -> %d\n", "- 54", ft_atoi("- 54"));
// 		// Expected: 0
// 	return (0);
// }
