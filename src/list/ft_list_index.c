/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_index.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/30 19:51:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:37:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	See ft_list_find.c
*/

size_t	ft_list_index(t_list *list, void *data_ref, int (*cmp)())
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		if (!cmp(data_ref, list->content))
			break ;
		ret++;
		list = list->next;
	}
	return (ret);
}
