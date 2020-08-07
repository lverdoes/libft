/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charsearch_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 12:12:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/07/07 14:46:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charsearch(const char c, const char *set)
{
	size_t i;

	i = 0;
	if (!set)
		return (0);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
