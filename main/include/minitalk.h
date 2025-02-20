/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:00 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/02/20 23:25:19 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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