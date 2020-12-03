/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_one_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 14:41:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
**	Delete one node from memory and set it to NULL.
**	This does not unlink the node cleanly from the list. 
*/

void	ft_node_del_one(t_node *node, void (*del)(void *))
{
	if (!node)
		return ;
	del(node->content);
	ft_free(node);
	node = NULL;
}
