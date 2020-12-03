/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_contains_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:09:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 11:35:08 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_contains(const char *str, const char *set)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_strchr(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}
