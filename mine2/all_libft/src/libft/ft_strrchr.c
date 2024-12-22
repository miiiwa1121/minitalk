/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:01:02 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:13 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == (char)c)
		last_occurrence = (char *)s;
	return (last_occurrence);
}

// int	main(void)
// {
// 	char	str[] = "Hello, world!";
// 	char	*result;

// 	result = ft_strrchr(str, 'o');
// 	if (result != NULL)
// 		printf("Last occurrence of 'o' is at position: %ld\n", result - str);
// 	else
// 		printf("'o' not found.\n");
// 	result = ft_strrchr(str, 'z');
// 	if (result != NULL)
// 		printf("Last occurrence of 'z' is at position: %ld\n", result - str);
// 	else
// 		printf("'z' not found.\n");
// 	return (0);
// }
