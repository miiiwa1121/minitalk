/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:01 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/28 22:08:31 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

// #include <stdio.h>

// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%d\n", *(int *)lst->content);
//         lst = lst->next;
//     }
// }

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
// 	t_list *newNode1 = create_elem(1);
// 	t_list *newNode2 = create_elem(2);
// 	t_list *newNode3 = create_elem(3);
// 	ft_lstadd_back(&head, newNode1);
// 	ft_lstadd_back(&head, newNode2);
// 	ft_lstadd_back(&head, newNode3);
// 	print_list(head);
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
