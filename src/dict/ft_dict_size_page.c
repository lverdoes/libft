/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_size_page.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 21:27:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 00:05:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

static void	go_page(t_dict *dict, size_t *const size)
{
	int	i;

	*size += 1;
	if (!dict->d)
		return ;
	i = 0;
	while (dict->d[i] != NULL)
	{
		go_page(dict->d[i], size);
		i++;
	}
}

size_t	ft_dict_size_page(t_dict *head)
{
	size_t	size;

	if (!head)
		return (0);
	size = 0;
	go_page(head, &size);
	return (size);
}
