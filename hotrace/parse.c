/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 21:27:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/15 09:58:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	parse(t_trie *head, char *line)
{
	t_trie	*d;
	char	*ptr;
	char	*content;

	if (*line == '!')
	{
		d = ft_trie_find(head, line + 1);
		if (d)
		{
			free(d->content);
			d->content = NULL;
		}
	}
	else
	{
		ptr = strchr(line, '=');
		if (ptr)
		{
			*ptr = '\0';
			content = strdup(ptr + 1);
			if (!ft_trie_new(head, line, content))
				free(content);
		}
		else
		{
			d = ft_trie_find(head, line);
			if (d && d->content)
				printf("%s\n", d->content);
			else
				printf("%s: Not found\n", line);
		}
	}
	return (0);
}
