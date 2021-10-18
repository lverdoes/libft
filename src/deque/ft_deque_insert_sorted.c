/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_insert_sorted.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 16:06:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 21:51:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdio.h>

static size_t	find_pos(t_deque *d, void *new_element, int (*cmp)(), size_t begin, size_t end)
{
	size_t	middle;
	int		ret;

	//segv in this func
	//printf("cmp begin [%lu] and end [%lu]\n", begin, end);
	if (begin == end)	
		return (begin);
	middle = (end + begin) / 2;
	ret = cmp(d->array[middle], new_element);
	if (ret < 0)	//new ele is bigger than [middle], move to right
		return (find_pos(d, new_element, cmp, middle, end));
	if (ret > 0)	//[middle] is biggger than new_ele, move left
		return (find_pos(d, new_element, cmp, begin, middle));
	return (middle);
}

int	ft_deque_insert_sorted(t_deque *d, void *new_element, int (*cmp)())
{
	size_t	pos;

	if (cmp(d->array[d->back], new_element) < 0)
		return (ft_deque_add_back(d, new_element));
	if (cmp(d->array[d->front], new_element) > 0)
		return (ft_deque_add_front(d, new_element));
	pos = find_pos(d, new_element, cmp, d->front, d->back);
	printf("pos = [%lu]\n", pos);
	return (ft_deque_insert(d, pos, new_element));
}
