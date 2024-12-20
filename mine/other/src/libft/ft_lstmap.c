/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:42:36 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/29 23:23:14 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*new_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (new_elem == NULL)
		{
			ft_lstclear(&new_lst, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

// // 関数: データを2倍にする
// void *double_content(void *data)
// {
// 	int *new_data = (int *)malloc(sizeof(int));
// 	if (!new_data)
// 		return (NULL);
// 	*new_data = *(int *)data * 2;
// 	return (new_data);
// }

// // 関数: データを解放する
// void del_func(void *data)
// {
// 	free(data);
// }

// #include <stdio.h>

// // ヘルパー関数: リストの内容を表示
// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d\n", *(int *)lst->content);
//         lst = lst->next;
//     }
// }

// // ヘルパー関数: 新しいリスト要素を作成
// t_list *create_elem(int content)
// {
//     t_list *new_elem = (t_list *)malloc(sizeof(t_list));
//     if (!new_elem)
//         return (NULL);
//     int *content_ptr = (int *)malloc(sizeof(int));
//     if (!content_ptr)
//     {
//         free(new_elem);
//         return (NULL);
//     }
//     *content_ptr = content;
//     new_elem->content = content_ptr;
//     new_elem->next = NULL;
//     return (new_elem);
// }

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *newNode1 = create_elem(42);
// 	t_list *newNode2 = create_elem(84);
// 	t_list *newNode3 = create_elem(126);

// 	// リストにノードを追加
// 	head = newNode1;
// 	newNode1->next = newNode2;
// 	newNode2->next = newNode3;

// 	// 元のリストの内容を表示
// 	printf("Original list:\n");
// 	print_list(head);

// 	// ft_lstmapを使用して新しいリストを作成
// 	t_list *mapped_list = ft_lstmap(head, double_content, del_func);

// 	// 新しいリストの内容を表示
// 	printf("Mapped list:\n");
// 	print_list(mapped_list);

// 	// メモリ解放
// 	ft_lstclear(&head, del_func);
// 	ft_lstclear(&mapped_list, del_func);

// 	return (0);
// }
