/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_find_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 00:25:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*ft_node_find(t_node *node, void *data_ref, int (*cmp)())
{
	while (node)
	{
		if (!cmp(data_ref, node->content))
			return (node);
		node = node->next;
	}
	return (NULL);
}
