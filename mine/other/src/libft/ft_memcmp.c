/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:13:40 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/22 23:52:05 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cp;
	const unsigned char	*s2_cp;
	size_t				i;

	i = 0;
	s1_cp = (const unsigned char *)s1;
	s2_cp = (const unsigned char *)s2;
	while (i < n)
	{
		if (s1_cp[i] != s2_cp[i])
			return (s1_cp[i] - s2_cp[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *sgm1;
// 	char *sgm2;
// 	size_t n;
// 	int ans;

// 	n = 3;

// 	sgm1 = "1234567890";
// 	sgm2 = "1234567890";
// 	ans = ft_memcmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);

// 	sgm1 = "1234567890";
// 	sgm2 = "2234567890";
// 	ans = ft_memcmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);

// 	sgm1 = "2234567890";
// 	sgm2 = "1234567890";
// 	ans = ft_memcmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);

// 	sgm1 = "1334567890";
// 	sgm2 = "1234567890";
// 	ans = ft_memcmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);

// 	sgm1 = "1234567890";
// 	sgm2 = "12345678\0'80";
// 	ans = ft_memcmp(sgm1, sgm2, n);
// 	printf("\nft_strncmp %d \n", ans);
// }