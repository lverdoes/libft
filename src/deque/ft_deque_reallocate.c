/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_reallocate.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 15:11:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdlib.h>
#include "libft.h"

int	ft_deque_reallocate(t_deque *d, size_t capacity)
{
	t_deque	new;

	if (d->capacity >= capacity)
		return (1);
	new.array = ft_calloc(capacity, sizeof(void *));
	if (!new.array)
		return (0);
	new.capacity = capacity;
	new.size = d->size;
	new.front = (new.capacity - d->size) / 2;
	if (d->size)
	{
		new.back = new.front + d->size - 1;
		ft_memcpy(&new.array[new.front], &d->array[d->front], d->size * sizeof(void *));
	}
	else
	{
		new.back = new.front;
	}
	free(d->array);
	ft_memcpy(d, &new, sizeof(t_deque));
	return (1);
}
