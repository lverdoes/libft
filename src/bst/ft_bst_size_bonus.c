/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bst_size_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 14:44:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/09 15:54:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	count_nodes(t_bst *node, size_t ret)
{
	if (!node)
		return (ret);
	ret++;
	ret = count_nodes(node->left, ret);
	ret = count_nodes(node->right, ret);
	return (ret);
}

size_t  		ft_bst_size(t_bst *node)
{
	return (count_nodes(node, 0));
}
