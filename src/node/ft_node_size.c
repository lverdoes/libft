/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:18:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 08:25:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_node_size(t_node *node)
{
	size_t ret;

	ret = 0;
	while (node)
	{
		node = node->next;
		ret++;
	}
	return (ret);
}
