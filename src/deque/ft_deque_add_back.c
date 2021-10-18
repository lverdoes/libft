/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_add_back.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/17 20:50:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deque_add_back(t_deque *d, void *new_element)
{
	if (d->size == 0)
	{
		d->array[d->back] = new_element;
		d->size++;
		return (1);
	}
	if (d->back + 1 == d->capacity)
	{
		if (!ft_deque_reserve(d, d->capacity * 2))
			return (0);
	}
	d->back++;
	d->array[d->back] = new_element;
	d->size++;
	return (1);
}
