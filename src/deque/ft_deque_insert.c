/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_insert.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 21:47:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 12:29:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "libft.h"

int	ft_deque_insert(t_deque *d, size_t position, void *new_element, size_t amount)
{
	size_t	amount_shift_left;
	size_t	amount_shift_right;
	void	*dst;
	void	*src;
	size_t	shift;

	if (position < d->front)
		return (ft_deque_add_front(d, new_element));
	if (position > d->back)
		return (ft_deque_add_back(d, new_element));
	if (d->size + 1 >= d->capacity)
	{
		if (ft_deque_reserve(d, d->capacity * 2))
			return (0);
	}
	amount_shift_left = position - d->front + 1;
	amount_shift_right = d->back - position + 1;
	if (amount_shift_left > amount_shift_right)
	{
		dst = &d->array[position + 1];
		src = &d->array[position];
		shift = amount_shift_right;
	}
	else
	{
		dst = &d->array[d->front - 1];
		src = &d->array[d->front];
		shift = amount_shift_left;
	}
	ft_memmove(dst, src, shift * sizeof(void *));
	d->array[position] = new_element;
	return (1);
}
