/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substrlen_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/02 17:21:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/01 11:03:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_substrlen(const char *str, const char *set)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	if (!set)
		return (ft_strlen(str));
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (i);
}
