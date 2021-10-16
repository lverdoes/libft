/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_bits.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 23:00:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/16 09:08:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char src)
{
	unsigned char	str[8];
	unsigned int	i;

	i = 8;
	while (i)
	{
		i--;
		if (src & 1)
			str[i] = '1';
		else
			str[i] = '0';
		src >>= 1;
	}
	write(1, str, 8);
}
