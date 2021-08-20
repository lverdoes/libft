/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_leaks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:22:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/08/12 17:57:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#if defined __APPLE__

int	ft_leaks(char *program_name)
{
	char	cmd[136];

	if (ft_strlen(program_name) > 100)
		return (0);
	ft_strlcpy(cmd, "leaks ", 136);
	ft_strlcat(cmd, &program_name[2], 136);
	ft_strlcat(cmd, " | grep \"total leaked bytes\"", 136);
	system(cmd);
	return (1);
}

#endif
