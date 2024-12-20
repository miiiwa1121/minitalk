/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:59:50 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 05:44:52 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*found;

// 	str = "Hello,'\0'world!";
// 	found = ft_strchr(str, '\0');
// 	if (found != NULL)
// 		printf("'o' found at position: %ld\n", found - str);
// 	else
// 		printf("'o' not found.\n");
// 	found = ft_strchr(str, 'z');
// 	if (found != NULL)
// 		printf("'z' found at position: %ld\n", found - str);
// 	else
// 		printf("'z' not found.\n");
// 	return (0);
// }
