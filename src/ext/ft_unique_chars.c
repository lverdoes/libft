/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unique_chars.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:36:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/09 22:51:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unique_chars(const char *str)
{
	int		tab[256];
	size_t	i;

	ft_bzero(tab, sizeof(tab));
	i = 0;
	while (str[i] != '\0')
	{
		if (tab[(unsigned char)str[i]])
			return (0);
		tab[(unsigned char)str[i]]++;
		i++;
	}
	return (1);
}
