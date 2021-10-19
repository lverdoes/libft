/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 20:09:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

/*
**	Delete one node from memory.
**	This does not unlink the node cleanly from the list.
**	See ft_node_del_all.c for more info.
*/

void	ft_list_del_one(t_list *list, void (*del)(void *))
{
	if (!list)
		return ;
	del(list->content);
	free(list);
}
