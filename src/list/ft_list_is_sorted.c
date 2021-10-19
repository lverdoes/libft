/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_is_sorted.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 19:48:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 19:43:52 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	If sorted in ascending order, 1 is returned.
**	If data is equal or listsize == 1, 1 is returned.
**	If not sorted, 0 is returned.
*/

int	ft_list_is_sorted(t_list *head, int (*cmp)())
{
	int		ret;
	t_list	*tmp;
	t_list	*prev;

	prev = head;
	tmp = head->next;
	while (tmp)
	{
		ret = cmp(prev->content, tmp->content);
		if (ret > 0)
			return (0);
		prev = tmp;
		tmp = tmp->next;
	}
	return (1);
}
