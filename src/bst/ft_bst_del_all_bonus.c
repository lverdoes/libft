/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bst_del_all_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 12:28:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/09 14:17:11 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_bst_del_all(t_bst **head, void (*del)(void *))
{
	t_bst *tmp;
	
	if (!*head)
		return ;
	tmp = *head;
	ft_bst_del_all(&tmp->left, del);
	ft_bst_del_all(&tmp->right, del);
	ft_bst_del_one(*head, *del);
	*head = NULL;
}
