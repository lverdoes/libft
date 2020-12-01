/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_insert_before_bonus.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 20:47:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_node_insert_before(t_node **head, t_node *node, t_node *before_this)
{
	if (before_this == *head)
	{
		ft_node_add_front(head, node);
		return ;
	}
	node->prev = before_this->prev;
	node->next = before_this;
	before_this->prev = node;
	node->prev->next = node;	
}
