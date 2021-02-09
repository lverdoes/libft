/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_unlink.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:36:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 08:25:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_unlink(t_node **head, t_node *node)
{
	if (!node->prev)
	{
		*head = node->next;
		(*head)->prev = NULL;
	}
	else if (!node->next)
	{
		node->prev->next = NULL;
	}
	else
	{	
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->prev = NULL;
	node->next = NULL;
}
