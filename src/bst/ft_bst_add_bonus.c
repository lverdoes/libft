/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bst_add_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 12:18:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/15 10:26:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

void	ft_bst_add(t_bst **head, t_bst *new, int (*cmp)())
{
	t_bst *tmp;

	tmp = *head;
	while (tmp)
	{
		new->prev = tmp;
		if (cmp(new->content, tmp->content) > 0)
		{
			tmp = tmp->right;
			if (!tmp)
				new->prev->right = new;
		}
		else if (cmp(new->content, tmp->content) < 0)
		{
			tmp = tmp->left;
			if (!tmp)
				new->prev->left = new;
		}
		else
		{
			tmp->num += 1;
			ft_bst_del_one(new, free);
			return ;
		}
	}
}
