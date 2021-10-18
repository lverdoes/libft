/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_reserve.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/17 21:38:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_deque_reserve(t_deque *d, size_t capacity)
{
	t_deque	new;

	if (d->capacity >= capacity)
		return (0);
	new.array = ft_calloc(capacity, sizeof(void *));
	if (!new.array)
		return (0);
	new.capacity = capacity;		printf("new capa=[%lu]\n", new.capacity);
	new.size = d->size;				printf("new size=[%lu]\n", new.size);
	new.front = (new.capacity - d->size) / 2;	printf("new fron=[%lu]\n", new.front);
	if (d->size)
		new.back = new.front + d->size - 1;
	else
		new.back = new.front;		printf("new back=[%lu]\n", new.back);
	if (d->size)
		ft_memcpy(&new.array[new.front], &d->array[d->front], d->size * sizeof(void *));
	free(d->array);
	ft_memcpy(d, &new, sizeof(t_deque));
	return (1);
}
