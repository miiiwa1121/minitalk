/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:19 by jtakahas          #+#    #+#             */
/*   Updated: 2025/03/13 15:05:05 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <limits.h>

static char	*pass_space(char *str)

{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static int	check_plus_minus(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;//符号をスキップ
	}
	return (sign);
}

static bool	is_int(long long num, int sign)
{
	if (sign == 1 && num > __INT_MAX__)
		return (false);
	if (sign == -1 && num * -1 < INT_MIN)
		return (false);
	return (true);
}

bool	bool_atoi(char *str, int *nbr)
{
	int			sign;//符号を保持
	long long	ans;//計算結果を保持

	if (str == NULL)
		return (false);
	sign = 1;
	ans = 0;
	str = pass_space(str);//空白をスキップ
	sign = check_plus_minus(str);//符号を取得
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))//数字でない場合
			return (false);
		ans = (*str - '0') + (ans * 10);//桁を上げながら整数化していく
		if (!is_int(ans, sign))//intの範囲外の場合
			return (false);
		str++;
	}
	*nbr = ans * sign;//符号を反映
	return (true);
}
