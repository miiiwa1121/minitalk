/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:00:22 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 00:05:50 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	to_copy;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	to_copy = srclen;
	if (srclen >= dstsize)
		to_copy = dstsize - 1;
	ft_memcpy(dst, src, to_copy);
	dst[to_copy] = '\0';
	return (srclen);
}

// int	main(void)
// {
// 	char src[] = "Hello, world!";
// 	char dest[20];

// 	size_t len = ft_strlcpy(dest, src, sizeof(dest));

// 	printf("Copied string: %s\n", dest);
// 	printf("Copied length: %zu\n", len);
// 	return (0);
// }