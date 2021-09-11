/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_delone.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 20:28:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/03 20:30:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_delone(t_stack *s, void (*f)(void *))
{
	if (s->size)
		f(s->data[s->size - 1]);
}
