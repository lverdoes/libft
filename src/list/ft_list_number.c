/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/27 17:27:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Return the node at index position number.
**	For number = 0, head is returned.
**	If number is out range, NULL is returned.
*/

t_list	*ft_list_number(t_list *list, size_t number)
{
	t_list	*tmp;
	size_t	i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		if (i == number)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
