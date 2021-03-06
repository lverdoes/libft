/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_insert_sort.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:31:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:12:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_insert_sort(t_node **head, t_node *node, int (*cmp)())
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(node->content, tmp->content) <= 0)
		{
			ft_node_insert_before(head, node, tmp);
			return ;
		}
		tmp = tmp->next;
	}
	ft_node_add_back(head, node);
}
