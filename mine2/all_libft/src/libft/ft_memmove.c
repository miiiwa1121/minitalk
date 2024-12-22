/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:20:55 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 05:07:59 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s < d && s + n > d)
	{
		s += n;
		d += n;
		while (n--)
		{
			*--d = *--s;
		}
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	src[] = "Helloworld!";
// 	char	dest[20];

// 	ft_memmove(dest, src, 5);
// 	printf("%s\n", dest);
// 	if (dest != ft_memmove(dest, src, 8))
// 		write(1, "dest's adress was not returned\n", 31);
// 	write(1, dest, 22);
// 	write(1, "\n", 1);

// 	return (0);
// }
