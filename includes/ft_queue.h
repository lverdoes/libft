/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_queue.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/27 19:58:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/09/11 11:31:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stddef.h>
# include <stdio.h>

typedef struct s_queue
{
	void	**data;
	size_t	capacity;
	size_t	length;
	size_t	front;
	size_t	end;
}	t_queue;

void	ft_dequeue(t_queue *qq);
int		ft_enqueue(t_queue *q, void *data);
void	ft_queue_clear(t_queue *q);
void	*ft_queue_get_element(t_queue *q, size_t index);
t_queue	*ft_queue_init(void);
int		ft_queue_resize(t_queue *q);

#endif
