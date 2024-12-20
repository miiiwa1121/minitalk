/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:22:43 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/16 20:46:06 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (n-- > 0)
	{
		*ptr = c;
		ptr++;
	}
	return (buf);
}

// int	main(void)
// {
// 	char	str[] = "123456789";

// 	ft_memset(str + 2, '*', 5);
// 	printf("%s\n", str); // 12*****89を期待
// 	return (0);
// }
