/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:08:12 by anarama           #+#    #+#             */
/*   Updated: 2024/04/21 17:08:39 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*mem;
	char	*temp_mem;
	size_t	total_size;

	total_size = size * num;
	if (num == 0 || size == 0)
		total_size = 0;
	if (SIZE_MAX / num < size)
		return (NULL);
	mem = (char *)malloc(total_size);
	if (!mem)
		return (NULL);
	temp_mem = mem;
	while (total_size > 0)
	{
		*mem++ = 0;
		total_size--;
	}
	return ((void *)temp_mem);
}

char	*ft_strchr(char *str, char c)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*cat_result;
	char	*temp_cat_result;

	if (s1 == NULL)
	{
		cat_result = ft_strdup(s2);
		return (ft_free(&s2), cat_result);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	cat_result = (char *)ft_calloc((len_s1 + len_s2) + 1, 1);
	if (!cat_result)
		return (ft_free(&s1), ft_free(&s2), NULL);
	temp_cat_result = cat_result;
	ft_memcpy(cat_result, s1, len_s1);
	cat_result += len_s1;
	ft_memcpy(cat_result, s2, len_s2);
	return (ft_free(&s1), ft_free(&s2), temp_cat_result);
}

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*dup_s;
	char	*temp_dup_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	dup_s = (char *)malloc(sizeof(char) * len_s + 1);
	if (!dup_s)
		return (NULL);
	temp_dup_s = dup_s;
	while (*s)
		*dup_s++ = *s++;
	*dup_s = '\0';
	return (temp_dup_s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	char		*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	while (n--)
		*temp_dest++ = *temp_src++;
	return (dest);
}
