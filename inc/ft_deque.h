/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:25:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 12:29:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stddef.h>

typedef struct s_deque
{
	void	**array;
	size_t	capacity;
	size_t	size;
	size_t	front;
	size_t	back;
}	t_deque;

void	ft_deque_init(t_deque *d, size_t reserve);
int		ft_deque_insert(t_deque *d, size_t position, void *new_element, size_t amount);
int		ft_deque_add_back(t_deque *deque, void *new_element);
int		ft_deque_add_front(t_deque *deque, void *new_element);
void	ft_deque_clear(t_deque *deque, void (*del)(void *));
int		ft_deque_reserve(t_deque *d, size_t capacity);

#endif
