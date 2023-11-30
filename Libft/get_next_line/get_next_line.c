/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:09:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/10/12 16:25:56 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char	*st_buffer, int fd)
{
	int		char_read;
	char	*buffer;

	char_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (char_read > 0 && ft_strchr(st_buffer, '\n') == NULL)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (free(buffer), free(st_buffer), NULL);
		buffer[char_read] = '\0';
		if (char_read > 0)
			st_buffer = ft_strjoin(st_buffer, buffer);
	}
	free (buffer);
	return (st_buffer);
}

char	*get_next_line(int fd)
{
	static char	*st_buffer;
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_buffer = read_file(st_buffer, fd);
	if (!st_buffer)
		return (free(st_buffer), NULL);
	line_to_return = ft_strtrim(st_buffer, '\n');
	st_buffer = ft_strtrim_the_rest(st_buffer, '\n');
	return (line_to_return);
}
