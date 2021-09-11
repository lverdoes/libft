/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue_get_element.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 22:39:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/27 22:43:43 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	*ft_queue_get_element(t_queue *q, size_t index)
{
	if (q->front + index >= q->length)
		return (NULL);
	return (q->data[q->front + index]);
}
