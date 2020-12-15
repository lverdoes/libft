/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_str_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 21:10:38 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/05 22:11:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_sort_str(char **array)
{
	size_t size;
	size_t i;
	size_t j;

	size = ft_array_size((const char **)array);
	if (size < 2)
		return ;
	size -= 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (ft_strncmp(array[j], array[j + 1], ft_strlen(array[j]) + 1) > 0)
				ft_swap(array + j, array + j + 1, sizeof(char *));
			j++;
		}
		i++;
	}
}
