/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_before.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/11/08 16:45:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_before(t_list **head, t_list *new, t_list *before_this)
{
	if (!before_this)
	{
		ft_list_add_back(head, new);
		return ;
	}
	if (before_this == *head)
	{
		ft_list_add_front(head, new);
		return ;
	}
	new->prev = before_this->prev;
	new->next = before_this;
	before_this->prev = new;
	new->prev->next = new;
}
