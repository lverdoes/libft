/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_number_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/11/28 21:22:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Return the node at index position number.
**	For number = 0, head is returned.
**	If number is out range, NULL is returned.
*/

t_node	*ft_node_number(t_node *node, size_t number)
{
	size_t i;

	i = 0;
	while (node)
	{
		if (i == number)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}
