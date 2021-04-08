/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:13:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 21:29:28 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

t_dict	*ft_dict_find(t_dict *head, char *str)
{
	int		i;
	t_dict	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	tmp = head;
	while (str[i])
	{
		if (tmp && tmp->dict[(int)str[i]])
		{
			tmp = tmp->dict[(int)str[i]];
			i++;
		}
		else
			return (NULL);
	}
	return (tmp);
}
