/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_bits.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 22:54:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/15 23:30:10 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char src)
{
	unsigned char	dst;
	unsigned int	i;

	dst = 0;
	i = 8;
	while (i)
	{
		i--;
		dst <<= 1;
		if (src & 1)
			dst |= 1;
		src >>= 1;
	}
	return (dst);
}
