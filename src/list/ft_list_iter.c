/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_iter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:04:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:51:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_iter(t_list *list, void (*f)(void *))
{
	if (!f)
		return ;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
