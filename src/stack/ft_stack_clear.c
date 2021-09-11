/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_clear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:00:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 12:17:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdlib.h>
#include "libft.h"

void	ft_stack_clear(t_stack *s, void (*f)(void *))
{
	size_t	i;

	i = 0;
	while (i < s->size)
	{
		f(s->data[i]);
		i++;
	}
	free(s->data);
	ft_bzero(s, sizeof(t_stack));
}
