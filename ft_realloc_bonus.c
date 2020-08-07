/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:17:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/08/02 14:28:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static void		copy_ptrs(char **dst, char **src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static size_t	get_size_of_src(char **src)
{
	size_t i;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != NULL)
		i++;
	return (i);
}

char			**ft_realloc(char **src, char *line)
{
	size_t	size;
	char	**dst;

	size = get_size_of_src(src);
	dst = ft_calloc(size + 2, sizeof(char *));
	if (!dst)
		return (free_array(src, size));
	copy_ptrs(dst, src, size);
	free(src);
	dst[size] = ft_strdup(line);
	if (!dst[size])
		return (free_array(dst, size));
	return (dst);
}
