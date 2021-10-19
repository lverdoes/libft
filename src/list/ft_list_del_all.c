/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_del_all.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:36:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/19 21:34:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
**	Delete the complete linked list.
**
**	Example of a DEL() function with a struct t_var:
**
**	typedef struct	s_var{
**		int			value;
**		char		*str;
**	}				t_var;
**	
**	void	del_var(void *var)
**	{
**		t_var *tmp;
**
**		tmp = var;
**		free(tmp->str);
**		free(tmp);
**	}
**
**	Calling		'ft_list_del_all(&head, del_var);'	will delete the list
**
*/

void	ft_list_del_all(t_list **head, void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (!head)
		return ;
	start = *head;
	while (start)
	{
		tmp = start;
		start = start->next;
		ft_list_del_one(tmp, del);
	}
	*head = NULL;
}
