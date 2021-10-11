/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trie_alloc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 17:56:13 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/10/07 18:30:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trie.h"
#include "libft.h"

t_trie	*ft_trie_alloc(void)
{
	return (ft_calloc(1, sizeof(t_trie)));
}
