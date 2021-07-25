/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_clear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:39:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/25 17:00:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include <stdlib.h>

static void	ft_trie_del_one(t_trie *trie, void (*del)(void *))
{
	if (!trie)
		return ;
	del(trie->content);
	free(trie);
}

static void	go_node(t_trie *trie, void (*del)(void *))
{
	int	i;

	i = 0;
	while (i < NODES)
	{
		if (trie->trie[i])
			go_node(trie->trie[i], del);
		i++;
	}
	ft_trie_del_one(trie, del);
}

void	ft_trie_clear(t_trie **head, void (*del)(void *))
{
	if (!head)
		return ;
	go_node(*head, del);
	*head = NULL;
}
