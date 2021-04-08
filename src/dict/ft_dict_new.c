/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:22:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 21:29:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include <stdlib.h>

static t_dict	*create_node(void)
{
	t_dict	*dst;
	int		i;
	
	dst = malloc(sizeof(t_dict));
	if (!dst)
		return (NULL);
	dst->content = NULL;
	i = 0;
	while (i < PAGES)
	{
		dst->dict[i] = NULL;
		i++;
	}
	return (dst);
}

int	ft_dict_new(t_dict **head, void *content, char const *const str)
{
	int		i;
	t_dict	*tmp;

	if (!*head)
	{
		*head = create_node();
		if (!*head)
			return (-1);
	}
	tmp = *head;
	i = 0;
	while (str[i])
	{
		if (tmp->dict[(int)str[i]])
		{
			tmp = tmp->dict[(int)str[i]];
			i++;
		}
		else
		{
			tmp->dict[(int)str[i]] = create_node();
			if (!tmp->dict[(int)str[i]])
				return (-1);
		}
	}
	if (tmp->content)
		return (0);
	tmp->content = content;
	return (1);
}
