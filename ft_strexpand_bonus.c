/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strexpand_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/02 16:37:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2020/08/02 17:33:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strexpand(char *src1, const char *src2, char *tar, size_t tar_len)
{
	size_t len;
	char *dst;

	if (!src1 || tar < src1 || tar_len > ft_strlen(src1))
		return (NULL);
	len = ft_strlen(src1) - tar_len + ft_strlen(src2);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src1, tar - src1 + 1); 
	ft_strlcat(dst, src2, len + 1);
	ft_strlcat(dst, tar + tar_len, len + 1);
	return (dst);
}