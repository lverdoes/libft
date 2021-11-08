/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:35:58 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/11/08 16:46:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_new(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
