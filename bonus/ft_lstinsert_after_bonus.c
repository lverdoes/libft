/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstinsert_after_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 23:08:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/15 00:04:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	insert_node(t_list **head, t_list *node, t_list *after_this)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp == after_this)
		{
			node->next = after_this->next;
			tmp->next = node;
		}
		tmp = tmp->next;
	}
}

static void	remove_node_from_list(t_list **head, t_list *node)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_lstinsert_after(t_list **head, t_list *node, t_list *after_this)
{	
	if (!*head || !node || node == after_this)
		return ;
	if (!after_this)
	{
		ft_lstmove_back(head, node);
		return ;
	}
	remove_node_from_list(head, node);
	insert_node(head, node, after_this);
}
