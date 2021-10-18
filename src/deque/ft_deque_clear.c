/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_clear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/17 21:49:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdlib.h>

void	ft_deque_clear(t_deque *d, void (*del)(void *))
{
	size_t	i;

	if (!d)
		return ;
	i = 0;
	while (i < d->capacity)
	{
		del(d->array[i]);
		i++;
	}
	free(d->array);
}
