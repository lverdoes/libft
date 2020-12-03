/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_iter_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:04:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 14:41:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

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