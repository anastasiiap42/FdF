/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:09:34 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/20 21:34:11 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_strjoin_gnl(char **s1, char *s2)
{
	int		x;
	char	*new;

	x = -1;
	if (!(*s1))
	{
		*s1 = (char *)malloc(1 * sizeof(char));
		if (!(*s1))
			return (-1);
		*s1[0] = '\0';
	}
	if (!s2)
		return (-1);
	new = (char *)malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (-1);
	while (*s1[++x])
		new[x] = *s1[x];
	while (*s2)
		new[x++] = *s2++;
	new[x] = '\0';
	free(*s1);
	*s1 = new;
	return (1);
}

static int	ft_strtrim_gnl(char *s1, char set, char **str)
{
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	if (!s1 || !s1[0])
		return (0);
	while (s1[i] && s1[i] != set)
		i++;
	if (s1[i] == set)
		i++;
	*str = (char *)malloc((i + 1) * sizeof(char));
	if (!(*str))
		return (-1);
	while (i--)
		(*str)[l++] = *s1++;
	(*str)[l] = '\0';
	return (1);
}

static int	ft_strtrim_the_rest(char **s1, char set)
{
	char	*str;
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	if (!(*s1) || !set || !(*s1)[0])
		return (0);
	while ((*s1)[i] && (*s1)[i] != set)
		i++;
	if ((*s1)[i] == set)
		i++;
	str = (char *)malloc((ft_strlen(*s1) - i + 1) * sizeof(char));
	if (!str)
		return (-1);
	while (i < ft_strlen(*s1))
		str[l++] = (*s1)[i++];
	str[l] = '\0';
	free(*s1);
	*s1 = str;
	if (ft_strlen(*s1) == 0)
		return (0);
	return (1);
}

static int	read_file(char **st_buffer, int fd)
{
	int		char_read;
	char	*buffer;
	int		status;

	status = 0;
	char_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	while (char_read > 0 && ft_strchr(*st_buffer, '\n') == NULL)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (free(buffer), free(*st_buffer), -1);
		buffer[char_read] = '\0';
		if (char_read > 0)
			status = ft_strjoin_gnl(st_buffer, buffer);
		if (status == -1)
			return (free(buffer), status);
	}
	free(buffer);
	return (1);
}

int	get_next_line(int fd, char **line_to_return, int run_id)
{
	static char	*st_buffer;
	int			temp;
	static int	i;

	i = 0;
	*line_to_return = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (read_file(&st_buffer, fd) == -1)
		return (free(st_buffer), -1);
	if (ft_strtrim_gnl(st_buffer, '\n', line_to_return) == -1)
		return (-1);
	temp = ft_strtrim_the_rest(&st_buffer, '\n');
	if (temp == -1)
		return (-1);
	if (temp == 0 && ft_strlen(*line_to_return) != 0)
	{
		if (run_id == 2)
			free(st_buffer);
		return (0);
	}
	else
		return (ft_strlen(*line_to_return));
}
