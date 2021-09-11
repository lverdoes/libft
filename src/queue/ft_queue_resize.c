/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue_resize.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 21:14:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 12:17:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include <stdlib.h>
#include "libft.h"

int	ft_queue_resize(t_queue *q)
{
	void	**new_data;

	if (q->length > q->capacity / 2)
	{
		new_data = malloc(2 * q->capacity * sizeof(void *));
		if (!new_data)
			return (0);
		ft_memcpy(&new_data[0], &q->data[q->front], q->length * sizeof(void *));
		free(q->data);
		q->data = new_data;
		q->capacity = q->capacity * 2;
	}
	else
		ft_memcpy(&q->data[0], &q->data[q->front], q->length * sizeof(void *));
	q->front = 0;
	q->end = q->length;
	return (1);
}
