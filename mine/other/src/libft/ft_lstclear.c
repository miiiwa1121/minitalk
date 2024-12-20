/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:51 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/28 23:03:34 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// void	del_func(void *data)
// {
// 	free(data);
// }

// #include<stdio.h>

// // ヘルパー関数：リストの内容を表示
// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d\n", *(int *)lst->content);
//         lst = lst->next;
//     }
// }

// // ヘルパー関数：新しいリスト要素を作成
// t_list *create_elem(int content)
// {
//     t_list *new_elem = (t_list *)malloc(sizeof(t_list));
//     if (!new_elem)
//         return NULL;
//     int *content_ptr = (int *)malloc(sizeof(int));
//     if (!content_ptr)
//     {
//         free(new_elem);
//         return NULL;
//     }
//     *content_ptr = content;
//     new_elem->content = content_ptr;
//     new_elem->next = NULL;
//     return new_elem;
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

// 	// 削除前のリストを表示
// 	printf("Before clear:\n");
// 	print_list(head);

// 	// リストを全て削除
// 	ft_lstclear(&head, del_func);

// 	// 削除後のリストを表示
// 	printf("After clear:\n");
// 	if (head == NULL)
// 	{
// 		printf("List is empty\n");
// 	}
// 	else
// 	{
// 		print_list(head);
// 	}

// 	return (0);
// }