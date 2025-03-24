/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:32:51 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/24 15:53:30 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../all_libft/include/libft.h"
# include <signal.h>

# ifdef __linux__
#  define WAIT_TIME 1125
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

#endif