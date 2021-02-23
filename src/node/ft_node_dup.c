/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_dup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:55:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/23 08:37:07 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	typedef struct	s_var{
**		int			num;
**		char		*str;
**	}				t_var;
**
**	int		cmp_str(void *data_ref, t_var *var)
**	{
**		return (ft_strcmp(data_ref, var->str));
**	}
**	
**	int		cmp_num(t_var *t1, t_var *t2)
**	{
**		return (t1->num - t2->num);
**	}
**	
**	t_var	*dup_var(t_var *src)
**	{
**		t_var *dst;
**		
**		dst = ft_calloc(1, sizeof(t_var));
**		dst->num = src->num;
**		dst->str = ft_strdup(src->str);
**		if (!dst->str)
**			return (ft_free_ptr(dst));
**		return (dst);
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
**	Example: 
**	t_node *dup = ft_node_dup(head, "Rigate", cmp_str, (void *)dup_var, del_var)
**	will create a new list with only nodes where var->str is equal to "Rigate".
*/

t_node	*ft_node_dup(t_node *head, void *data_ref, int (*cmp)(), void *(*dup)(void *), void (*del)(void *))
{
	t_node	*dup_head;
	void	*dup_content;
	t_node	*new;
	t_node	*tmp;

	dup_head = NULL;
	tmp = head;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
		{
			dup_content = dup(tmp->content);
			if (!dup_content)
			{
				ft_node_del_all(&dup_head, del);
				return (NULL);
			}
			new = ft_node_new(dup_content);
			if (!new)
			{
				del(dup_content);
				ft_node_del_all(&dup_head, del);
				return (NULL);
			}
			ft_node_add_back(&dup_head, new);
		}
		tmp = tmp->next;
	}
	return (dup_head);
}
