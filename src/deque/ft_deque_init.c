/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 14:41:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/17 21:31:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"
#include "libft.h"

void	ft_deque_init(t_deque *d, size_t reserve)
{
	const size_t	minimum_size = 3;

	ft_bzero(d, sizeof(t_deque));
	if (reserve < minimum_size)
		ft_deque_reserve(d, minimum_size);
	else
		ft_deque_reserve(d, reserve);
}
