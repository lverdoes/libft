/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deque_add_back.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 20:32:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/18 14:48:07 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deque_add_back(t_deque *d, void *new_element)
{
	return (ft_deque_insert(d, d->capacity, new_element));
}
