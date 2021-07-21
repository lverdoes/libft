/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:13:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/21 09:42:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"

t_trie	*ft_trie_find(t_trie *head, char *key)
{
	int		i;
	t_trie	*current;

	if (!key)
		return (NULL);
	i = 0;
	current = head;
	while (key[i])
	{
		if (current)
		{
			current = current->trie[(unsigned char)key[i]];
			i++;
		}
		else
			return (NULL);
	}
	return (current);
}
