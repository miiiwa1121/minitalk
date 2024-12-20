/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:36:41 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 03:01:26 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_module_fd(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = ft_module_fd(n);
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}
// int	main(void)
// {
// 	// int numbers[] = {0, 123, -123, 2147483647, -2147483648};
// 	// int num_elements = sizeof(numbers) / sizeof(numbers[0]);
// 	// for (int i = 0; i < num_elements; i++)
// 	// {
// 	// 	ft_putnbr_fd(numbers[i], STDOUT_FILENO);
// 	// 	write(STDOUT_FILENO, "\n", 1);
// 	// }
// 	ft_putnbr_fd(-2147483648LL, 2);
// 	return (0);
// }
