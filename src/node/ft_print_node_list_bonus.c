/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_node_list_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:06:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/03 14:41:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	get_magnitude(size_t num)
{
	size_t ret;

	ret = 1;
	while (num > 9)
	{
		num = num / 10;
		ret++;
	}
	return (ret);
}

static void	put_indentation_space(size_t i, size_t len)
{
	size_t magnitude_len;
	size_t magnitude_i;
	size_t spaces;

	len--;
	magnitude_len = get_magnitude(len);
	magnitude_i = get_magnitude(i);
	spaces = magnitude_len - magnitude_i;
	while (spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		spaces--;
	}
}

void	ft_print_list_node(t_node *node)
{
	size_t len;
	size_t i;

	len = ft_node_size(node);
	i = 0;
	while (node)
	{
		ft_putchar_fd('[', 1);
		put_indentation_space(i, len);
		ft_putnbr_fd((int)i, 1);
		ft_putstr_fd("] ", 1);
		ft_putchar_fd('[', 1);
		if (sizeof(t_node) == 3 * sizeof(void *))
			ft_putstr_fd(node->content, 1);
		else
			ft_putnbr_fd((int)&node->content, 1);
		ft_putendl_fd("] ", 1);
		i++;
		node = node->next;
	}
}
