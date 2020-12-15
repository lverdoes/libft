/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bst_new_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 12:20:01 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/09 12:20:19 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_bst	*ft_bst_new(void *content, int num)
{
	t_bst *new;

	new = ft_calloc(1, sizeof(t_bst));
	if (!new)
		return (NULL);
	new->content = content;
	new->num = num;
	new->left = NULL;
	new->right = NULL;
	new->prev = NULL;
	return (new);
}
