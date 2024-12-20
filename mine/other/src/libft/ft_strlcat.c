/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:02:23 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/30 16:16:30 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	dst_len;
// 	size_t	src_len;

// 	if (!src)
// 		return (0);
// 	src_len = ft_strlen(src);
// 	if (!dst || dstsize == 0)
// 		return (src_len);
// 	dst_len = ft_strlen(dst);
// 	if (dst_len >= dstsize)
// 		return (src_len + dstsize);
// 	if (src_len < dstsize - dst_len - 1)
// 	{
// 		ft_memcpy(dst + dst_len, src, src_len);
// 		dst[dst_len + src_len] = '\0';
// 	}
// 	else
// 	{
// 		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
// 		dst[dstsize - 1] = '\0';
// 	}
// 	return (dst_len + src_len);
// }

// int	main(void)
// {
// 	char	dest[10] = "12345";
// 	char	src[] = "42tokyo";
// 	size_t	result;

// 	result = ft_strlcat(dest, src, 0);
// 	printf("%zu\n", result);
// 	printf("%s\n", dest);
// 	result = strlcat(dest, src, 0);
// 	printf("%zu\n", result);
// 	printf("%s\n", dest);
// 	return (0);
// }
