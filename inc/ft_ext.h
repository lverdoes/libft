/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ext.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 11:25:02 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/11/08 16:50:43 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXT_H
# define FT_EXT_H

# include <stddef.h>

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

char	*ft_append(char *s1, const char *s2);
size_t	ft_array_size(void **array);
char	**ft_arraydup(char **array, size_t size);
double	ft_atod(const char *str);
char	*ft_concat_array(char **array, char *delim);
size_t	ft_counter(const char *s, const char *set);
void	*ft_free(void *ptr);
void	*ft_free_array(void **array, size_t i);
int		*ft_intdup(const int *src, size_t len);
int		ft_iswhitespace(int c);
void	ft_print_array(char **array);
void	ft_print_int_array(int *array, size_t size);
void	**ft_realloc(void **src, void *ptr, size_t *size);
char	*ft_replace(char *s1, const char *s2, char *ptr, size_t ptr_len);
t_uchar	reverse_bits(unsigned char src);
void	print_bits(unsigned char src);
char	**ft_split_strchr(const char *srs, const char *set, size_t *size);
char	**ft_split_strnstr(const char *src, const char *set, size_t *size);
int		ft_str_contains_none(const char *str, const char *set);
int		ft_str_contains_only(const char *str, const char *set);
void	ft_str_to_lower(char *str);
void	ft_str_to_upper(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strxjoin(const char *src, ...);
size_t	ft_substrlen(const char *str, const char *set);
void	ft_swap(void *a, void *b, size_t size_datatype);
int		ft_unique_chars(const char *str);

/*
** # define GET_STRING(n) #n
** # define CONCATENATE(a, b) a##b
** # define FT_MIN(a, b)({ \
** 	typeof (a) _a = (a); \
** 	typeof (b) _b = (b); \
** 	_a < _b ? _a : _b;})
** # define FT_MAX(a, b)({ \
** 	typeof (a) _a = (a); \
** 	typeof (b) _b = (b); \
** 	_a > _b ? _a : _b;})
** # define FT_SWAP(a, b)({\
** 	typeof (a) _a = (a); \
** 	typeof (b) _b = (b); \
** 	typeof (*a) _tmp = (*(a)); \
** 	(*(_a)) = (*(_b)); \
** 	(*(_b)) = (_tmp);})
*/

#endif
