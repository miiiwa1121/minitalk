/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:42:08 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/28 23:10:02 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// void	process_func(void *data)
// {
// 	printf("Data: %p\n", data);
// }

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

// 	// リストの内容を表示（適用前）
// 	printf("Before applying function:\n");
// 	print_list(head);

// 	// ft_lstiterを使用して、リストの各要素に対して関数を適用
// 	ft_lstiter(head, process_func);

// 	// リストの内容を表示（適用後）
// 	printf("After applying function:\n");
// 	print_list(head);

// 	// メモリ解放
// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp->content);
// 		free(temp);
// 	}

// 	return (0);
// }