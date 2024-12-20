/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 07:29:39 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/27 10:08:29 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int main(void)
// {
//     int data = 42;

//     t_list *node = ft_lstnew(&data);

//     if (node)
//     {
//         int *content_ptr = (int *)node->content;
//         printf("Content of the node: %d\n", *content_ptr);

//         if (node->next == NULL)
//             printf("Next pointer is NULL\n");
//         else
//             printf("Next pointer is not NULL\n");

//         free(node);
//     }
//     else
//     {
//         printf("Failed to create the node\n");
//     }

//     return (0);
// }
