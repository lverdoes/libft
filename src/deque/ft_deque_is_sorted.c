/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_is_sorted.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 15:29:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 21:24:26 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deque_is_sorted(const t_deque *d, int (*cmp)())
{
	size_t	left;
	size_t	right;

	left = d->front;
	right = d->front + 1;
	while (left < d->back)
	{
		if (cmp(d->array[left], d->array[right]) > 0)
			return (0);
		left++;
		right++;
	}
	return (1);
}
