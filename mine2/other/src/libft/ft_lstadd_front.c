/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:04:21 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/27 11:00:53 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// #include <stdio.h>

// int main()
// {
//     t_list *list = ft_lstnew("A");
//     t_list *new_node = ft_lstnew("X");

//     ft_lstadd_front(&list, new_node);

//     // リストの内容を出力して確認
//     t_list *current = list;
//     while (current)
//     {
//         printf("%s -> ", (char *)current->content);
//         current = current->next;
//     }
//     printf("NULL\n");

//     // メモリ解放
//     while (list)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }
