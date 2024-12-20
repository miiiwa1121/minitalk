/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:40:28 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/29 16:10:36 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int main() {
//     // リストの準備
//     t_list *head = NULL; // リストの先頭ポインタ

//     // リストに要素を追加する（例として3つの要素を追加する）
//     for (int i = 0; i < 3; ++i) {
//         // 新しい要素を作成
//         t_list *new_node = (t_list *)malloc(sizeof(t_list));
//         if (!new_node) {
//             perror("メモリ割り当てエラー");
//             exit(EXIT_FAILURE);
//         }
//         // データを設定（ここではint型の値を設定してみる）
//         int *content_ptr = (int *)malloc(sizeof(int));
//         if (!content_ptr) {
//             perror("メモリ割り当てエラー");
//             exit(EXIT_FAILURE);
//         }
//         *content_ptr = i; // 0, 1, 2 という連続する値を設定
//         new_node->content = content_ptr;
//         new_node->next = NULL;
//         // リストに要素を追加
//         if (head == NULL) {
//             head = new_node;
//         } else {
//             t_list *last = ft_lstlast(head);
//             last->next = new_node;
//         }
//     }

//     // リストの最後のノードを取得
//     t_list *lastNode = ft_lstlast(head);
//     // 最後のノードが存在する場合はそのデータを表示
//     if (lastNode) {
//         int *lastcontent = (int *)lastNode->content;
//         printf("リストの最後のノードのデータ: %d\n", *lastcontent);
//     } else {
//         printf("リストが空です。\n");
//     }

//     // リストのメモリ解放（実際のアプリケーションでは全ての要素を解放する必要がある）
//     t_list *current = head;
//     while (current) {
//         t_list *temp = current;
//         current = current->next;
//         free(temp->content);  // データのメモリを解放
//         free(temp);        // ノードのメモリを解放
//     }

//     return 0;
// }