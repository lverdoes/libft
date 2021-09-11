/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_resize.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 13:05:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 12:15:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

int	ft_stack_resize(t_stack *s)
{
	void	**new_data;

	new_data = ft_calloc(s->capacity * 2, sizeof(void *));
	if (!new_data)
		return (0);
	ft_memcpy(new_data, s->data, s->size * sizeof(void *));
	free(s->data);
	s->data = new_data;
	s->capacity *= 2;
	return (1);
}
