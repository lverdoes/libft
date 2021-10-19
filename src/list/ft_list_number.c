/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:53:21 by lverdoes      ########   odam.nl         */
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
	size_t	i;

	i = 0;
	while (list)
	{
		if (i == number)
			return (list);
		i++;
		list = list->next;
	}
	return (NULL);
}
