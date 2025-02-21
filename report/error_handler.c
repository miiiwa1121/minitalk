/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:57:55 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/02/21 06:17:33 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

#include <stdlib.h>
#include <unistd.h>

void	error_handler(const char *msg, const char *details)//エラーメッセージを表示してプログラムを終了
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);//エラーメッセージを表示
	if (details)
		ft_putstr_fd((char *)details, 2);//エラーの詳細を表示
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);//プログラムを即時終了
}
