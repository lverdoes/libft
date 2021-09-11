/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getfile.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 22:45:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/09 20:06:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "ft_ext.h"
#include <unistd.h>
#include <stdlib.h>

static int	clean_up(void *str, void *buffer)
{
	free(str);
	free(buffer);
	return (GNL_ERROR);
}

int	ft_getfile(int fd, char **str)
{
	int		ret;
	char	*buffer;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !str)
		return (GNL_ERROR);
	*str = ft_strdup("");
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!*str || !buffer)
		return (clean_up(str, buffer));
	while (1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (clean_up(str, buffer));
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		*str = ft_append(*str, buffer);
		if (!*str)
			return (clean_up(str, buffer));
	}
	free(buffer);
	return (GNL_END);
}
