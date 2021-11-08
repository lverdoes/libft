/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_bits.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 23:00:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/31 18:38:51 by lverdoes      ########   odam.nl         */
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
		str[i] = '0' + (src & 1);
		src >>= 1;
	}
	write(1, str, 8);
}
