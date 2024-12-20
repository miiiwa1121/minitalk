/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:15 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/28 22:20:50 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del_func(void *data)
// {
// 	free(data);
// }

// #include<stdio.h>

// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d\n", *(int *)lst->content);
//         lst = lst->next;
//     }
// }

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*node_to_delete;
// 	int		*content1;
// 	int		*content2;

// 	// 1つ目のノードを作成
// 	content1 = (int *)malloc(sizeof(int));
// 	if (!content1)
// 		return (1);
// 	*content1 = 42;

// 	head = (t_list *)malloc(sizeof(t_list));
// 	if (!head)
// 	{
// 		free(content1);
// 		return (1);
// 	}
// 	head->content = content1;
// 	head->next = NULL;

// 	// 2つ目のノードを作成
// 	content2 = (int *)malloc(sizeof(int));
// 	if (!content2)
// 		return (1);
// 	*content2 = 84;

// 	node_to_delete = (t_list *)malloc(sizeof(t_list));
// 	if (!node_to_delete)
// 	{
// 		free(content2);
// 		return (1);
// 	}
// 	node_to_delete->content = content2;
// 	node_to_delete->next = NULL;

// 	// リストに2つ目のノードを追加
// 	head->next = node_to_delete;

// 	// 削除前のリストを表示
// 	printf("Before deletion:\n");
// 	print_list(head);

// 	// ノードを削除
// 	ft_lstdelone(node_to_delete, &del_func);
// 	head->next = NULL;  // 削除されたノードをリストから切り離す

// 	// 削除後のリストを表示
// 	printf("After deletion:\n");
// 	print_list(head);

// 	// メモリ解放
// 	free(head->content);
// 	free(head);

// 	return (0);
// }
