/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 00:19:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:37:09 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Returns the first node from START that matches DATA_REF,
**	according to CMP.
**	CMP can be a function that returns strcmp(), for example:
**
**	int		cmp_ref(void *data_ref, t_var *var)
**	{
**		return (ft_strcmp(data_ref, var->str));
**	}
*/

t_list	*ft_list_find(t_list *list, void *data_ref, int (*cmp)())
{
	while (list)
	{
		if (!cmp(data_ref, list->content))
			return (list);
		list = list->next;
	}
	return (NULL);
}
