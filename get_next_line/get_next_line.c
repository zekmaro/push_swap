/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:14:30 by anarama           #+#    #+#             */
/*   Updated: 2024/05/23 21:21:20 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char const *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*extract_line(char	**leftovers)
{
	char	*line;
	char	*newline_index;
	size_t	len_line;
	char	*new_leftovers;

	newline_index = ft_strchr_gnl(*leftovers, '\n');
	if (newline_index)
	{
		len_line = newline_index - *leftovers + 1;
		line = ft_calloc_gnl(len_line + 1, 1);
		if (!line)
			return (ft_free_gnl(leftovers), NULL);
		line = ft_memcpy_gnl(line, *leftovers, len_line);
		new_leftovers = ft_strdup_gnl(newline_index + 1);
		ft_free_gnl(leftovers);
		if (!new_leftovers)
			return (ft_free_gnl(&line), NULL);
		*leftovers = new_leftovers;
	}
	else
	{
		line = ft_strdup_gnl(*leftovers);
		ft_free_gnl(leftovers);
	}
	return (line);
}

void	ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*leftovers = NULL;
	ssize_t		read_bytes;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr_gnl(leftovers, '\n') == NULL)
	{
		buffer = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (ft_free_gnl(&leftovers), ft_free_gnl(&buffer), NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_free_gnl(&buffer), NULL);
		if (read_bytes == 0)
		{
			ft_free_gnl(&buffer);
			if (leftovers == NULL || *leftovers == '\0')
				return (ft_free_gnl(&leftovers), NULL);
			break ;
		}
		leftovers = ft_strjoin_gnl(leftovers, buffer);
	}
	return (extract_line(&leftovers));
}
