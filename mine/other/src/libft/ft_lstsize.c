/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:40:08 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/27 11:24:42 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include "libft.h"
// #include <stdio.h>

// int main()
// {
//     t_list *list = ft_lstnew("A");
//     ft_lstadd_front(&list, ft_lstnew("B"));
//     ft_lstadd_front(&list, ft_lstnew("C"));

//     int size = ft_lstsize(list);
//     printf("List size: %d\n", size);  // 出力: List size: 3

//     // メモリ解放
//     while (list)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }
