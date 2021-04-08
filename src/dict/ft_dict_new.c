/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:22:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/09 00:27:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include "libft.h"
#include "ft_ext.h"
#include <stdlib.h>

static t_dict	*create_node(void)
{
	t_dict	*dst;
	int		i;

	dst = ft_calloc(1, sizeof(t_dict));
	if (!dst)
		return (NULL);
	ft_memset(dst->num, -1, sizeof(dst->num));
	return (dst);
}

int	ft_dict_new(t_dict **head, char *key, void *content)
{
	t_dict	*dict;
	t_dict	**tmp;
	t_dict	*new;
	int		i;
	int		j;
	size_t	size;

	if (!*head)
		*head = create_node();
	if (!*head)
		return (-1);
	dict = *head;
	i = 0;
	while (key[i])
	{
		j = dict->num[(int)key[i]];
		if (j < 0)
		{
			new = create_node();
			if (!new)
				return (-1);
			tmp = (t_dict **)ft_realloc((void **)dict->d, new, &size);
			if (!tmp)
			{
				free(new);
				return (-1);
			}
			free(dict->d);
			dict->d = tmp;
			dict->num[(int)key[i]] = size - 1;
			j = dict->num[(int)key[i]];
		}
		dict = dict->d[j];
		i++;
	}
	if (dict->content)
		return (0);
	dict->content = content;
	return (1);
}
