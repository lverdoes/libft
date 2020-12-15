/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bst_del_one_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 12:22:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/09 13:31:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_bst_del_one(t_bst *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->content);
	ft_free(node);
}
