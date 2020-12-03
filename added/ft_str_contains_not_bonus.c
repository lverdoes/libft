/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_contains_not_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:12:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 01:48:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_contains_not(const char *str, const char *set)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}
