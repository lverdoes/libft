/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hotrace.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 13:25:01 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/15 10:52:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static size_t	find_empty_line(t_line *lines)
{
	static size_t	i = 0;

	while (TRUE)
	{
		if (lines[i].state == READY_FOR_INPUT)
		{
			pthread_mutex_lock(&lines[i].mutex_gnl);
			break;
		}
		if (i == MAX - 1)
			i = 0;
		else
			i += 1;
	}
	return (i);
}

static void	*read_input_thread(void *const ptr)
{
	size_t	i;
	t_vars	*v = ptr;

	while (TRUE)
	{
		i = find_empty_line(v->lines);
		//dprintf(1, "Please enter a word:\n");
		v->ret = get_next_line(STDIN_FILENO, &v->lines[i].str);
		if (v->ret == -1)
			break;
		v->lines[i].state = READY_FOR_OUTPUT;
		if (v->ret == 0)
			break;
		pthread_mutex_unlock(&v->lines[i].mutex_gnl);
	}
	pthread_mutex_unlock(&v->lines[i].mutex_gnl);
	dprintf(2, "GNL has stopped with return: [%d]\n", v->ret);
	v->end = TRUE;
	return (NULL);
}

static size_t	find_ready_line(t_line *lines, t_bool *const end)
{
	size_t	i = 0;

	while (!(*end))
	{
		if (pthread_mutex_trylock(&lines[i].mutex_thr) == PTHREAD_SUCCESS)
		{
			if (lines[i].state == READY_FOR_OUTPUT)
			{
				pthread_mutex_lock(&lines[i].mutex_gnl);
				lines[i].state = BEING_PROCESSED;
				break;
			}
			pthread_mutex_unlock(&lines[i].mutex_thr);
		}
		if (i >= MAX - 1)
			i = 0;
		else
			i += 1;
	}
	return (i);
}

static void	*clean_up_line(t_line lines[], size_t i)
{
	free(lines[i].str);
	lines[i].str = NULL;
	lines[i].state = READY_FOR_INPUT;
	pthread_mutex_unlock(&lines[i].mutex_thr);
	pthread_mutex_unlock(&lines[i].mutex_gnl);
	return (NULL);
}

static void	*process_input_thread(void *const ptr)
{
	t_vars	*v = ptr;
	size_t	i;

	while (TRUE)
	{
		i = find_ready_line(v->lines, &v->end);
		if (v->ret < 1)
			break;
		//dprintf(1, "tid [%p]: [%lu] You typed: %s!\n", pthread_self(), i, v->lines[i].str);
		parse(v->head, v->lines[i].str);
		clean_up_line(v->lines, i);
	}
	clean_up_line(v->lines, i);
	pthread_exit(NULL);
	return (NULL);
}

int	hotrace(int argc, char **argv, char **env)
{
	t_vars		*v;
	pthread_t	*threads;

	init(&v, &threads);

	for (int i = 0; i < THREADS; i++)
	{
		if (pthread_create(&threads[i], NULL, &process_input_thread, v))
			dprintf(2, "An error occurred while creating threads\n");
	}

	read_input_thread(v);

	//write thread?

	for (int i = 0; i < THREADS; i++)
	{
		if (pthread_join(threads[i], NULL))
			dprintf(2, "An error occurred while joining threads\n");
	}

	destroy(v, threads);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	hotrace(argc, argv, env);
	while (1){}
	return (0);
}
