/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 17:56:13 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/21 09:48:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include "libft.h"

t_trie	*ft_trie_init(void)
{
	t_trie	*node;

	node = ft_calloc(1, sizeof(t_trie));
	return (node);
}
