/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_last_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:27:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 00:30:00 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*ft_node_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
