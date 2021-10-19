/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:18:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 22:03:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_size(t_list *list)
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		list = list->next;
		ret++;
	}
	return (ret);
}
