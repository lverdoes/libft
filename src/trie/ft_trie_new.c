/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:22:08 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/21 09:44:26 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include "libft.h"

int	ft_trie_new(t_trie *head, char *key, void *content)
{
	int		i;
	t_trie	*current;
	t_trie	*next;

	current = head;
	i = 0;
	while (key[i])
	{
		next = current->trie[(unsigned char)key[i]];
		if (!next)
		{
			next = ft_trie_init();
			if (!next)
				return (TRIE_ERROR_MALLOC);
			current->trie[(unsigned char)key[i]] = next;
		}
		current = next;
		i++;
	}
	if (current->content)
		return (TRIE_ERROR_EXISTING_PAIR);
	current->content = content;
	return (TRIE_SUCCESS);
}
