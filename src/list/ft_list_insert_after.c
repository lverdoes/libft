/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_after.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:45:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_after(t_list **head, t_list *new_list, t_list *after_this)
{
	if (!after_this)
	{
		ft_list_add_back(head, new_list);
		return ;
	}
	new_list->prev = after_this;
	new_list->next = after_this->next;
	after_this->next = new_list;
	if (new_list->next)
		new_list->next->prev = new_list;
}
