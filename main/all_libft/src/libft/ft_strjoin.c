/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:28:07 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/22 11:09:17 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_tmp;
	int		len;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str_tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_tmp);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*text[10];
// 	char	*result;

// 	text[0] = "1";
// 	text[1] = "2";
// 	text[2] = "3";
// 	text[3] = "4";
// 	text[4] = "a";
// 	text[5] = "b";
// 	text[6] = "cd";
// 	text[7] = ">?";
// 	text[8] = ":>?";
// 	text[9] = "102";
// 	result = ft_strjoin(text[7], text[9]);
// 	if (!result)
// 	{
// 		printf("Error: memory allocation failed\n");
// 		return (1);
// 	}
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
