/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstinsert_before_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 22:35:23 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/15 00:04:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	insert_node(t_list **head, t_list *node, t_list *before_this)
{
	t_list *tmp;

	tmp = (*head);
	while (tmp)
	{
		if (tmp->next == before_this)
		{
			node->next = before_this;
			tmp->next = node;
			return ;
		}
		tmp = tmp->next;
	}
}

static void	remove_node_from_list(t_list **head, t_list *node)
{
	t_list *tmp;
	t_list *prev;

	prev = *head;
	tmp = (*head)->next;
	while (tmp)
	{
		if (tmp == node)
		{
			prev->next = tmp->next;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_lstinsert_before(t_list **head, t_list *node, t_list *before_this)
{

	if (!*head || !node || node == before_this || node->next == before_this)
		return ;
	if (!before_this)
	{
		ft_lstmove_back(head, node);
		return ;
	}
	if (*head == before_this)
	{
		ft_lstmove_front(head, node);
		return ;
	}
	remove_node_from_list(head, node);
	insert_node(head, node, before_this);
}
