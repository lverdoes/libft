/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_ints_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 07:18:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 21:24:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_sort_ints(int *array, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] < array[j])
				ft_swap(array + i, array + j, sizeof(int));
			j++;
		}
		i++;
	}
}
