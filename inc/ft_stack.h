/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 09:44:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 11:31:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>

typedef struct s_stack
{
	void	**data;
	size_t	size;
	size_t	capacity;
}	t_stack;

void	ft_stack_clear(t_stack *s, void (*f)(void *));
void	*ft_stack_get_top(t_stack *s);
int		ft_stack_init(t_stack *s);
void	*ft_stack_pop(t_stack *s);
int		ft_stack_push(t_stack *s, void *content);
int		ft_stack_resize(t_stack *s);

#endif
