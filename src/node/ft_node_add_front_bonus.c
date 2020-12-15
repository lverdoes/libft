/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_add_front_bonus.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:32:40 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/10 00:20:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_node_add_front(t_node **head, t_node *new)
{
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
