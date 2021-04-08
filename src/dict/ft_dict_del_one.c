/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dict_del_one.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:34:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/08 20:16:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include <stdlib.h>

void	ft_dict_del_one(t_dict *dict, void (*del)(void *))
{
	int	i;

	if (!dict)
		return ;
	del(dict->content);
	free(dict->d);
	free(dict);
	dict = NULL;
}
