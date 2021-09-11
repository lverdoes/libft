/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dequeue.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 20:46:36 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/27 22:44:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include <stdlib.h>

void	ft_dequeue(t_queue *q)
{
	if (q->length == 0)
		return ;
	free(q->data[q->front]);
	q->front++;
	q->length--;
}
