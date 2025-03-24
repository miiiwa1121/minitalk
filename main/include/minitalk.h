/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:00 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/24 15:53:25 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../all_libft/include/libft.h"
# include <signal.h>

# ifdef __linux__
#  define WAIT_TIME 1100
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50
# endif

#endif