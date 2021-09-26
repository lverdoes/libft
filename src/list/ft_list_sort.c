/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 21:31:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/26 11:50:08 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_ext.h"

void	ft_list_sort(t_list *head, int (*cmp)())
{
	t_list	*i;
	t_list	*j;

	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (cmp(i->content, j->content) > 0)
				ft_swap(&i->content, &j->content, sizeof(void *));
			j = j->next;
		}
		i = i->next;
	}
}
