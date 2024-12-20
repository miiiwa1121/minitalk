/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:16:34 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/02 09:21:17 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "123456789";
// 	result = ft_substr(str, 14, 6);
// 	if (result)
// 	{
// 		printf("Result: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Error: ft_substr returned NULL\n");
// 	}
// 	return (0);
// }