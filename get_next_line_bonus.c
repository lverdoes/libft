/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:51:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/08/02 14:30:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static size_t	str_endl(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char		*reset_ptr(char **str, int fd)
{
	char	*tmp;
	char	*dst;
	size_t	i;

	i = str_endl(str[fd]);
	dst = ft_substr(str[fd], 0, i);
	if (!dst)
	{
		free(str[fd]);
		return (NULL);
	}
	tmp = str[fd];
	str[fd] = ft_strdup(str[fd] + i + 1);
	free(tmp);
	return (dst);
}

static char		*strjoin_and_free(char *s1, char *s2, size_t i, size_t j)
{
	char	*dst;
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	dst = ft_calloc(len_1 + len_2 + 1, sizeof(char));
	if (!dst)
	{
		free(s1);
		return (NULL);
	}
	while (i < len_1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (j < len_2)
	{
		dst[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (dst);
}

static int		read_file(int fd, char **str)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
	{
		free(str[fd]);
		return (-1);
	}
	buffer[ret] = '\0';
	str[fd] = strjoin_and_free(str[fd], buffer, 0, 0);
	if (!str[fd])
		return (-1);
	if (ret == 0)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[OPEN_MAX];

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("\0");
	if (!str[fd])
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(str[fd], '\n'))
		ret = read_file(fd, str);
	if (ret < 0)
		return (-1);
	*line = reset_ptr(str, fd);
	if (!*line)
		return (-1);
	return (ret);
}
