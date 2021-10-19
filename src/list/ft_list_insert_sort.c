/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_insert_sort.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:31:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:45:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_sort(t_list **head, t_list *new_list, int (*cmp)())
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(new_list->content, tmp->content) <= 0)
		{
			ft_list_insert_before(head, new_list, tmp);
			return ;
		}
		tmp = tmp->next;
	}
	ft_list_add_back(head, new_list);
}
