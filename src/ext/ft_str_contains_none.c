/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_contains_none.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:12:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/11/08 18:23:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_contains_none(const char *str, const char *set)
{
	char	tab[256];
	size_t	i;
	size_t	j;

	ft_bzero(tab, sizeof(tab));
	j = 0;
	while (set[j] != '\0')
	{
		tab[(unsigned char)set[j]] = 1;
		j++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (tab[(unsigned char)str[i]])
			return (0);
		i++;
	}
	return (1);
}
