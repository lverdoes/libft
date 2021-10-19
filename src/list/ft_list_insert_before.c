/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_before.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:45:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_before(t_list **head, t_list *new_list, t_list *before_this)
{
	if (!before_this)
	{
		ft_list_add_back(head, new_list);
		return ;
	}
	if (before_this == *head)
	{
		ft_list_add_front(head, new_list);
		return ;
	}
	new_list->prev = before_this->prev;
	new_list->next = before_this;
	before_this->prev = new_list;
	new_list->prev->next = new_list;
}
