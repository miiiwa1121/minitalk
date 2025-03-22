/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:33:00 by mtsubasa          #+#    #+#             */
/*   Updated: 2025/03/22 19:21:03 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../all_libft/include/libft.h"
# include <signal.h>

# ifdef __linux__
#  define WAIT_TIME 1250//2000
# endif

# ifdef __APPLE__
#  define WAIT_TIME 50//50
# endif

#endif