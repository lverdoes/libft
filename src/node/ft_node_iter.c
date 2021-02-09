/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_iter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:04:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 19:14:33 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_iter(t_node *node, void (*f)(void *))
{
	if (!f)
		return ;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
