/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unique_chars_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:36:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 01:38:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_unique_chars(const char *str)
{
	size_t i;
	size_t j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
