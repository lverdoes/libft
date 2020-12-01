/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_all_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:36:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 19:33:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Delete the complete list from memory. All nodes are set to NULL.
*/

void	ft_node_del_all(t_node **head, void (*del)(void *))
{
	t_node *tmp;
	
	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_node_del_one(tmp, *del);
	}
}