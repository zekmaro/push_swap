/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:07:04 by anarama           #+#    #+#             */
/*   Updated: 2024/04/22 11:42:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *s)
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

	newline_index = ft_strchr(*leftovers, '\n');
	if (newline_index)
	{
		len_line = newline_index - *leftovers + 1;
		line = ft_calloc(len_line + 1, 1);
		if (!line)
			return (ft_free(leftovers), NULL);
		line = ft_memcpy(line, *leftovers, len_line);
		new_leftovers = ft_strdup(newline_index + 1);
		ft_free(leftovers);
		if (!new_leftovers)
			return (ft_free(&line), NULL);
		*leftovers = new_leftovers;
	}
	else
	{
		line = ft_strdup(*leftovers);
		ft_free(leftovers);
	}
	return (line);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*leftovers[MAX_FD] = {NULL};
	ssize_t		read_bytes;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	while (ft_strchr(leftovers[fd], '\n') == NULL)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (ft_free(&leftovers[fd]), ft_free(&buffer), NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_free(&leftovers[fd]), ft_free(&buffer), NULL);
		if (read_bytes == 0)
		{
			ft_free(&buffer);
			if (leftovers[fd] == NULL || *leftovers[fd] == '\0')
				return (ft_free(&leftovers[fd]), NULL);
			break ;
		}
		leftovers[fd] = ft_strjoin(leftovers[fd], buffer);
	}
	return (extract_line(&leftovers[fd]));
}
