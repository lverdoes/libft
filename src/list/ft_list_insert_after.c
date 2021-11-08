/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_after.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/11/08 16:46:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_after(t_list **head, t_list *new, t_list *after_this)
{
	if (!after_this)
	{
		ft_list_add_back(head, new);
		return ;
	}
	new->prev = after_this;
	new->next = after_this->next;
	after_this->next = new;
	if (new->next)
		new->next->prev = new;
}
