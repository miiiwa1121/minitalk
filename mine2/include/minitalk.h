/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:00 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/12/21 05:05:41 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../other/include/libft.h"
# include <signal.h>

typedef struct sigaction	t_sa;

# ifdef __linux__
#  define WAIT_TIME 2000
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

#endif