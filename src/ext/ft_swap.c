/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap_stdc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 09:21:18 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/26 11:49:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *a, void *b, size_t size_datatype)
{
	size_t			i;
	unsigned char	*arg1;
	unsigned char	*arg2;

	i = 0;
	arg1 = a;
	arg2 = b;
	while (i < size_datatype)
	{
		arg1[i] = arg1[i] ^ arg2[i];
		arg2[i] = arg1[i] ^ arg2[i];
		arg1[i] = arg1[i] ^ arg2[i];
		i++;
	}
}
