/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_pop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:07:29 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/09 10:13:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_stack_pop(t_stack *s)
{
	void	*popped;

	if (s->size == 0)
		return (NULL);
	popped = s->data[s->size];
	s->size--;
	return (popped);
}
