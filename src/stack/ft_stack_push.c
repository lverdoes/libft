/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_push.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 17:34:44 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/03 18:08:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stack_push(t_stack *s, void *content)
{
	if (s->size + 1 >= s->capacity)
		ft_stack_resize(s);
	s->data[s->size] = content;
	s->size++;
	return (1);
}
