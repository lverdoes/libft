/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_remove.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/25 15:13:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/25 17:00:38 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"

void	ft_trie_remove(t_trie *head, char *key, void (*del)(void *))
{
	t_trie	*node;

	node = ft_trie_find(head, key);
	if (node)
	{
		del(node);
		node->content = NULL;
	}
}
