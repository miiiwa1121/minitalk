/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:42:18 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:13 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cp;
	char	*src_cp;

	if (dst == src || n == 0)
		return (dst);
	dst_cp = (char *)dst;
	src_cp = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	dst[8];
// 	char	str[] = "01234'\0'56789";

// 	ft_memcpy(dst, str, 8);
// 	printf("%s\n", dst);
// 	return (0);
// }
