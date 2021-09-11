/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 21:56:53 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 12:18:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include <stdlib.h>

t_queue	*ft_queue_init(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->capacity = 2;
	q->data = malloc(q->capacity * sizeof(void *));
	q->length = 0;
	q->front = 0;
	q->end = 0;
	return (q);
}
