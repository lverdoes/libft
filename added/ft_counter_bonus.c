/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_counter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 10:29:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/09/22 12:13:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_counter(const char *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
