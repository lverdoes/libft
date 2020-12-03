/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open_file_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:19:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 13:23:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>
#include <unistd.h>

char	*ft_file_to_str(const char *filename)
{
	int		fd;
	char	*dst;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = ft_getline(fd, &dst);
	close(fd);
	if (ret < 0)
		return (NULL);
	return (dst);
}