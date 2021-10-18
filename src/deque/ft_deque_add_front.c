/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_add_front.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:03 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/17 20:49:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deque_add_front(t_deque *d, void *new_element)
{
	if (d->size == 0)
	{
		d->array[d->front] = new_element;
		d->size++;
		return (1);
	}
	if (d->front == 0)
	{
		if (!ft_deque_reserve(d, d->capacity * 2))
			return (0);
	}
	d->front--;
	d->array[d->front] = new_element;
	d->size++;
	return (1);
}
