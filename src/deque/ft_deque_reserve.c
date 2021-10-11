/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_reserve.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/11 20:32:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdlib.h>
#include "libft.h"

int	ft_deque_reserve(t_deque *d, size_t capacity)
{
	void	**new_array;
	size_t	shift;

	if (d->capacity >= capacity)
		return (0);
	new_array = malloc(capacity * sizeof(void **));
	if (!new_array)
		return (0);
	if (d->size == 0)
		return (1);
	shift = (capacity - d->capacity) / 2;
	ft_memcpy(&new_array[d->front - shift], &d->array[d->front], d->size);
	d->front -= shift;
	d->back -= shift;
	free(d->array);
	d->array = new_array;
	return (1);
}
