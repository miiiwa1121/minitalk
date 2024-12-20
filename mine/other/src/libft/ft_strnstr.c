/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:33:39 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/02 09:25:57 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fran
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len
			&& needle[j] != '\0')
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

// tokyo
// #include <stddef.h>
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	size_t	j;

// 	if (!haystack || !needle)
// 		return (NULL);
// 	if (!needle[0])
// 		return ((char *)haystack);
// 	i = 0;
// 	while (haystack[i] && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j] && (i + j) < len)
// 		{
// 			if (!needle[j + 1])
// 				return ((char *)&haystack[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// liu
// #include "libft.h"

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	nlen;

// 	if (needle == NULL || haystack == NULL)
// 		return (NULL);
// 	if (*needle == '\0')
// 		return ((char *)haystack);
// 	if (len == 0)
// 		return (NULL);
// 	nlen = ft_strlen(needle);
// 	while (*haystack && len-- >= nlen)
// 	{
// 		if (*haystack == *needle && ft_strncmp(haystack, needle, nlen) == 0)
// 			return ((char *)haystack);
// 		haystack++;
// 	}
// 	return (NULL);
// }

// tokyo1
// #include "libft.h"

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	size_t	j;

// 	if (!haystack || !needle)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	if (needle[j] == '\0')
// 		return ((char *)haystack);
// 	while (haystack[i] != '\0' && needle[j] != '\0' && i < len)
// 	{
// 		j = 0;
// 		if (haystack[i] == needle[0])
// 		{
// 			while (haystack[i + j] == needle[j] && (i + j) < len)
// 			{
// 				if (needle[j + 1] == '\0')
// 					return ((char *)haystack + i);
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*result1;
// 	char	*result2;

// 	// const char	haystack[20] = "TutorialsPoint";
// 	// const char	needle[10] = "to";
// 	result1 = ft_strnstr("libft", "libft", 5);
// 	result2 = strnstr("libft", "libft", 5);
// 	printf("The substring is: %s\n", result1);
// 	printf("The substring is: %s\n", result2);
// 	return (0);
// }
