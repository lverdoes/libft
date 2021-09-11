/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_get_top.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 18:37:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/03 18:38:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_stack_get_top(t_stack *s)
{
	if (s->size == 0)
		return (NULL);
	return (s->data[s->size - 1]);
}
