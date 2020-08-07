/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/02 17:21:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/08/02 17:26:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_substrlen(const char *str, const char *set)
{
	size_t i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_charsearch(str[i], set))
			return (i);
		i++;
	}
	return (i);
}