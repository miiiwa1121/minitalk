/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:32:51 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/23 17:47:35 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#endif