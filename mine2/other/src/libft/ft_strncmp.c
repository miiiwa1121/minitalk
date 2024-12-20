/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:25:21 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/30 15:30:00 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	const char *sgm1;
// 	const char *sgm2;
// 	size_t n;
// 	int ans;

// 	n = 10;

// 	sgm1 = "1234567890";
// 	sgm2 = "1234567890";
// 	ans = ft_strncmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);
// 	ans = strncmp(sgm1, sgm2, n);
// 	printf("strncmp    %d \n", ans);

// 	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
// 	printf("%d\n", strncmp("test\200", "test\0", 6));

// 	return (0);
// }