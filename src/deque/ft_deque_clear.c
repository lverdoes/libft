/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_clear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/11 20:34:33 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include <stdlib.h>

void	ft_deque_clear(t_deque **deque, void (*del)(void *))
{
	t_deque	*tmp;
	size_t	i;

	if (!deque)
		return ;
	tmp = *deque;
	i = 0;
	while (i < tmp->size)
	{
		del(&tmp->array[i]);
		i++;
	}
	free(tmp->array);
	*deque = NULL;
}
