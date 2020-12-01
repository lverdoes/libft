/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_insert_after_bonus.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 22:50:45 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_node_insert_after(t_node *node, t_node *after_this)
{
	node->prev = after_this;
	node->next = after_this->next;
	after_this->next = node;
	if (node->next)
		node->next->prev = node;
}
