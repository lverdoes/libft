/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_concat_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 21:15:19 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/20 11:09:46 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"
#include <stdlib.h>

/*
**	ft_concat_array is the opposite of ft_split
*/

static char	*concat_delim(char *dst, char **array, char *dl, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 1;
	while (i < size)
	{
		tmp = ft_strxjoin(dst, dl, array[i], NULL);
		free(dst);
		if (!tmp)
			return (NULL);
		dst = tmp;
		i++;
	}
	return (dst);
}

static char	*concat_no_delim(char *dst, char **array, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 1;
	while (i < size)
	{
		tmp = ft_strjoin(dst, array[i]);
		free(dst);
		if (!tmp)
			return (NULL);
		dst = tmp;
		i++;
	}
	return (dst);
}

char	*ft_concat_array(char **array, char *dl)
{
	char	*dst;
	size_t	size;

	size = ft_array_size((void **)array);
	if (size == 0)
		return (NULL);
	dst = ft_strdup(array[0]);
	if (!dst)
		return (NULL);
	if (dl)
		dst = concat_delim(dst, array, dl, size);
	else
		dst = concat_no_delim(dst, array, size);
	return (dst);
}
