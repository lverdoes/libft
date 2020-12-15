/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_concat_array_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 21:15:19 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/06 22:37:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char *concat_delim(
	char *dst, const char **array, char *delim, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 1;
	while (i < size)
	{
		tmp = ft_strxjoin(dst, delim, array[i], NULL);
		ft_free(dst);
		if (!tmp)
			return (NULL);
		dst = tmp;
		i++;
	}
	return (dst);
}

static char *concat_no_delim
	(char *dst, const char **array, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 1;
	while (i < size)
	{
		tmp = ft_strjoin(dst, array[i]);
		ft_free(dst);
		if (!tmp)
			return (NULL);
		dst = tmp;
		i++;
	}
	return (dst);
}

char	*ft_concat_array(const char **array, char *delim)
{
	char	*dst;
	size_t	size;

	size = ft_array_size(array);
	dst = ft_strdup(array[0]);
	if (!dst)
		return (NULL);
	if (delim)
		dst = concat_delim(dst, array, delim, size);
	else
		dst = concat_no_delim(dst, array, size);
	return (dst);
}
