/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:09:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/06 15:07:44 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
			st_buffer = ft_strjoin_gnl(st_buffer, buffer);
	}
	free (buffer);
	return (st_buffer);
}

char	*get_next_line(int fd)
{
	static char	*st_buffer[4096];
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_buffer[fd] = read_file(st_buffer[fd], fd);
	if (!st_buffer[fd])
		return (free(st_buffer[fd]), NULL);
	line_to_return = ft_strtrim_gnl(st_buffer[fd], '\n');
	st_buffer[fd] = ft_strtrim_the_rest(st_buffer[fd], '\n');
	//printf("%s\n", line_to_return);
	return (line_to_return);
}
