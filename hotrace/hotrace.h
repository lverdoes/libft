/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hotrace.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:48:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/15 10:16:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include "libft.h"
#include "get_next_line.h" 
#include "ft_trie.h"
#include "ft_list.h"
#include "ft_ext.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>

# define FALSE 0
# define TRUE 1
# define PTHREAD_SUCCESS 0

#define THREADS 5
#define MAX 6

typedef pthread_mutex_t	t_mutex;
typedef int t_bool;

enum e_string_state
{
	READY_FOR_INPUT,
	READY_FOR_OUTPUT,
	BEING_PROCESSED,
};

typedef struct s_line
{
	char	*str;
	t_bool	state;
	t_mutex	mutex_gnl;
	t_mutex	mutex_thr;
}	t_line;

typedef struct s_vars
{
	t_bool	end;
	int		ret;
	t_line	lines[MAX];
	t_trie	*head;
}	t_vars;

int	print(const char *line);
int	init(t_vars **v, pthread_t **threads);
int	destroy(t_vars *v, pthread_t *threads);
int	parse(t_trie *head, char *line);

#endif
