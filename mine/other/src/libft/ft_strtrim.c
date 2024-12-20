/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:42:14 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 15:19:40 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static	int	getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, &s1[start], end - start + 1);
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "   Hello, World!   ";
// 	char	set1[] = " ";
// 	char	*result1;
// 	char	str2[] = "---42Tokyo---";
// 	char	set2[] = "-";
// 	char	*result2;
// 	char	str3[] = "xxxxLibftxxxx";
// 	char	set3[] = "x";
// 	char	*result3;

// 	result1 = ft_strtrim(str1, set1);
// 	printf("Original: '%s'\n", str1);
// 	printf("Trimmed: '%s'\n", result1);
// 	free(result1);
// 	result2 = ft_strtrim(str2, set2);
// 	printf("Original: '%s'\n", str2);
// 	printf("Trimmed: '%s'\n", result2);
// 	free(result2);
// 	result3 = ft_strtrim(str3, set3);
// 	printf("Original: '%s'\n", str3);
// 	printf("Trimmed: '%s'\n", result3);
// 	free(result3);
// 	return (0);
// }
