/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_enqueue.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 20:44:24 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/27 22:13:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

int	ft_enqueue(t_queue *q, void *data)
{
	if (q->end == q->capacity)
	{
		if (!ft_queue_resize(q))
		{
			ft_queue_clear(q);
			return (0);
		}
	}
	q->data[q->end] = data;
	q->end++;
	q->length++;
	return (1);
}
