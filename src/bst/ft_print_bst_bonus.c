/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_bst_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 14:24:20 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/12/09 17:07:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
**	Call example:	ft_print_bst_list(head, ft_putstr_fd);
*/

static size_t get_last_leaf(t_bst *node, size_t ret, size_t right, size_t left)
{
	if (node->left)
		left = get_last_leaf(node->left, ret * 2, 0 ,0);
	if (node->right)
		right = get_last_leaf(node->right, ret * 2 + 1, 0, 0);
	if (left > right)
		return (left);
	if (left < right)
		return (right);
	return (ret);
}

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

static void	print_branch(t_bst *node, size_t i, size_t len, void (*print)())
{
	if (!node)
		return ;
	ft_putchar_fd('[', 1);
	put_indentation_space(i, len);
	ft_putnbr_fd((int)i, 1);
	ft_putstr_fd("] [", 1);
	ft_putnbr_fd(node->num, 1);
	ft_putstr_fd("] [", 1);
	print(node->content, 1);
	ft_putendl_fd("]", 1);
	print_branch(node->left, i * 2, len, print);
	print_branch(node->right, i * 2 + 1, len, print);
}

void		ft_print_bst(t_bst *node, void (*print)())
{
	size_t len;

	len = get_last_leaf(node, 1, 0 ,0);
	print_branch(node, 1, len, print);
}
