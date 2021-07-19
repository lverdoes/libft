/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_clear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 09:39:10 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/19 18:41:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"

static void	go_node(t_trie *trie, void (*del_content)(void *))
{
	int	i;

	i = 0;
	while (i < NODES)
	{
		if (trie->trie[i])
			go_node(trie->trie[i], del_content);
		i++;
	}
	ft_trie_del_one(trie, del_content);
}

void	ft_trie_clear(t_trie **head, void (*del_content)(void *))
{
	if (!head)
		return ;
	go_node(*head, del_content);
	*head = NULL;
}
