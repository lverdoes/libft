/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_join_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:18:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 14:41:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_node_join(t_node *left, t_node *right)
{
	left->next = right;
	right->prev = left;
}