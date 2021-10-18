/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_add_front.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:03 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 14:48:19 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deque_add_front(t_deque *d, void *new_element)
{
	return (ft_deque_insert(d, 0, new_element));
}
