/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:32:51 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/22 11:43:46 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef MINITALK_BONUS_H
// # define MINITALK_BONUS_H

// # include "../all_libft/include/libft.h"
// # include <signal.h>

// typedef struct sigaction	t_sa;

// # ifdef __linux__
// #  define WAIT_TIME 2000
// # endif

// # ifdef __APPLE__
// #  define WAIT_TIME 50
// # endif

// #endif

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../all_libft/include/libft.h"
# include <signal.h>

typedef struct sigaction	t_sa;

# ifdef __linux__
#  define WAIT_TIME 2000
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

// error_handler関数の宣言
void error_handler(const char *message, const char *usage);

// bool_atoi関数の宣言
int bool_atoi(const char *str, int *result);

#endif
