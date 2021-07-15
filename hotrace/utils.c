/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 15:13:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/15 10:18:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	init(t_vars **v, pthread_t **threads)
{
	*v = ft_calloc(1, sizeof(t_vars));
	*threads = malloc(THREADS * sizeof(pthread_t));
	(*v)->head = ft_calloc(1, sizeof(t_trie));
	for (int i = 0; i < MAX; i++)
	{
		pthread_mutex_init(&(*v)->lines[i].mutex_gnl, NULL);
		pthread_mutex_init(&(*v)->lines[i].mutex_thr, NULL);
	}
	return (0);
}

int	destroy(t_vars *v, pthread_t *threads)
{
	for (int i = 0; i < MAX; i++)
	{
		pthread_mutex_destroy(&v->lines[i].mutex_gnl);
		pthread_mutex_destroy(&v->lines[i].mutex_thr);
	}
	ft_trie_clear(v->head, free);
	free(v);
	free(threads);
	return (0);
}
