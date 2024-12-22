/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:19 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/22 11:07:39 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_string(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_print_string("(null)"));
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}
