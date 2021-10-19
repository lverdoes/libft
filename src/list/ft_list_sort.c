/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:31:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 22:07:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_ext.h"

void	ft_list_sort(t_list *left, int (*cmp)())
{
	t_list	*right;

	while (left)
	{
		right = left->next;
		while (right)
		{
			if (cmp(left->content, right->content) > 0)
				ft_swap(&left->content, &right->content, sizeof(void *));
			right = right->next;
		}
		left = left->next;
	}
}
