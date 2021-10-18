/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_insert.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 21:47:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 15:19:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "libft.h"
#      include <stdio.h>

static int	add_front(t_deque *d, void *new_element)
{
	d->front--;
	d->array[d->front] = new_element;
	d->size++;
	return (1);
}

static int	add_back(t_deque *d, void *new_element)
{
	d->back++;
	d->array[d->back] = new_element;
	d->size++;
	return (1);
}

static void	add_middle(t_deque *d, size_t position, void *new_element)
{
	size_t	amount_shift_left;
	size_t	amount_shift_right;
	void	*dst;
	void	*src;
	size_t	shift;

	amount_shift_left = position - d->front + 1;
	amount_shift_right = d->back - position + 1;
	if (amount_shift_left > amount_shift_right)
	{
		dst = &d->array[position + 1];
		src = &d->array[position];
		shift = amount_shift_right;
		d->back++;
	}
	else
	{
		dst = &d->array[d->front - 1];
		src = &d->array[d->front];
		shift = amount_shift_left;
		d->front--;
	}
	ft_memmove(dst, src, shift * sizeof(void *));
	d->array[position] = new_element;
	d->size++;
}

static int	check_reallocation(t_deque *d, size_t position)
{
	if (d->front == 0 || d->back + 1 == d->capacity)
	{
		if (!ft_deque_reallocate(d, d->capacity * 2))
			return (0);
	}
	return (1);
}

int	ft_deque_insert(t_deque *d, size_t position, void *new_element)
{
	if (d->size == 0)
	{
		d->array[d->front] = new_element;
		d->size++;
		return (1);
	}
	if (!check_reallocation(d, position))
		return (0);
	if (position < d->front)
		return (add_front(d, new_element));
	if (position > d->back)
		return (add_back(d, new_element));
	add_middle(d, position, new_element);
	return (1);
}
