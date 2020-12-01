/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_add_back_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:27:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 20:59:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Add a new unlinked node to the back of the list.
*/

void	ft_node_add_back(t_node **head, t_node *new)
{
	t_node *tmp;

	if (!*head)
		ft_node_add_front(head, new);
	tmp = ft_node_last(*head);
	tmp->next = new;
	new->prev = tmp;
}
