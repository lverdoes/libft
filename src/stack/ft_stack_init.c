/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 10:00:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/03 18:19:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"

int	ft_stack_init(t_stack *s)
{
	s->capacity = 8;
	s->data = ft_calloc(s->capacity, sizeof(void *));
	if (!s->data)
		return (0);
	s->size = 0;
	return (1);
}
