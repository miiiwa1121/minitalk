/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:50:45 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/02 09:31:51 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t	count;
// 	size_t	size;
// 	int		*arr;

// 	count = 9;
// 	size = sizeof(int);
// 	arr = ft_calloc(count, size);
// 	if (arr == NULL)
// 	{
// 		printf("メモリの割り当てに失敗しました。\n");
// 		return (1);
// 	}
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	free(arr);
// 	return (0);
// }
