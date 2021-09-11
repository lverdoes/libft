/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue_clear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 21:00:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 12:16:34 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include <stdlib.h>

void	ft_queue_clear(t_queue *q)
{
	size_t	i;

	i = 0;
	while (i < q->end)
	{
		free(q->data[i]);
		i++;
	}
	free(q->data);
	free(q);
}
