/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_clear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:39:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/08 20:22:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

static void	go_page(t_dict *dict, void (*del)(void *))
{
	int	i;

	if (!dict)
		return ;
	if (dict->d)
	{
		i = 0;
		while (dict->d[i] != NULL)
		{
			go_page(dict->d[i], del);
			i++;
		}
	}
	ft_dict_del_one(dict, del);
}

void	ft_dict_clear(t_dict **head, void (*del)(void *))
{
	if (!head)
		return ;
	go_page(*head, del);
}
