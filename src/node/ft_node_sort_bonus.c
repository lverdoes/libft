/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_sort_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:31:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 14:41:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void set_new_head(t_node **head, t_node *start, t_node *end, t_node *last)
{
	last->next = *head;
	(*head)->prev = last;
	start->next = NULL;
	*head = end;
}

static void find_next(t_node *node, t_node *select[2], int (*cmp)(), t_node *end)
{
	select[0] = node;
	select[1] = node;
	while (node != end)
	{
		if (cmp((select[0])->content, node->content) < 0)
			select[0] = node;
		else if (cmp((select[1])->content, node->content) > 0)
			select[1] = node;
		node = node->next;
	}
}

void		ft_node_sort(t_node **head, int (*cmp)())
{
	t_node *start;
	t_node *end;
	t_node *last;
	t_node *select[2];

	find_next(*head, select, cmp, NULL);
	ft_node_unlink(head, select[0]);
	ft_node_add_front(head, select[0]);
	ft_node_unlink(head, select[1]);
	ft_node_add_back(head, select[1]);
	start = *head;
	end = select[1];
	last = end;
	while (start->next != end)
	{
		find_next(start->next, select, cmp, end);
		ft_node_unlink(head, select[0]);
		ft_node_add_front(head, select[0]);
		ft_node_unlink(head, select[1]);
		ft_node_insert_after(select[1], last);
		last = last->next;
	}
	set_new_head(head, start, end, last);
}













// static t_node	*find_next_value(t_node *node, int (*cmp)())
// {
// 	t_node *ret;

// 	ret = node;
// 	while (node)
// 	{
// 		if (cmp(ret->content, node->content) < 0)
// 			ret = node;
// 		node = node->next;
// 	}
// 	return (ret);
// }

// void	ft_node_sort(t_node **head, int (*cmp)())
// {
// 	t_node *start;
// 	t_node *select;

// 	select = find_next_value(*head, cmp);
// 	ft_node_unlink(head, select);
// 	ft_node_add_front(head, node);
// 	start = *head;
// 	while (start->next)
// 	{
// 		select = find_next_value(start->next, cmp);
// 		ft_node_unlink(head, select);
// 		ft_node_add_front(head, node);
// 	}
// }