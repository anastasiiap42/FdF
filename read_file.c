/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:30 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 20:45:43 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	which_width(char *one_line)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (one_line[++i])
	{
		if (one_line[i] == ' '
			&& (one_line[i + 1] != ' ' || one_line[i + 1] != '\0'))
			res++;
		if (one_line[i] != ' ' && one_line[i + 1] == '\0')
			res++;
	}
	return (res);
}

static int	which_length(char *argv1, t_list *lst)
{
	int		res;
	char	*one_line;
	int		fd;
	int		status;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		return (perror("Open failed"), exit(1), -1);
	res = 0;
	status = 1;
	while (status > 0)
	{
		status = get_next_line(fd, &one_line, 1);
		if (status == 0)
			return (close(fd), free(one_line), res);
		if (status == -1)
			return (close(fd), free(one_line), -1);
		if (one_line[0] != '\0' && one_line[0] != '\n')
			lst->width = which_width(one_line);
		res++;
		free(one_line);
	}
	close(fd);
	return (res);
}

static int	fill_in_matrix(int *matrix_line, char *line)
{
	char	**map_line;
	int		c;

	map_line = ft_split(line, ' ');
	if (!map_line)
		return (0);
	c = -1;
	while (map_line[++c])
	{
		matrix_line[c] = ft_atoi(map_line[c]);
		free(map_line[c]);
	}
	free(map_line);
	return (1);
}

static int	malloc_matrix(char *argv1, t_list *lst)
{
	int	i;

	i = -1;
	lst->length = which_length(argv1, lst);
	if (lst->length < 0)
		return (0);
	lst->matrix = (int **)malloc(sizeof(int *) * (lst->length));
	if (!lst->matrix)
		return (0);
	while (++i < lst->length)
	{
		lst->matrix[i] = (int *)malloc(sizeof(int) * (lst->width));
		if (!lst->matrix[i])
			return (free(lst->matrix), 0);
	}
	return (1);
}

int	read_from_file(char	*argv1, t_list *lst, char *one_line)
{
	int		i;
	int		fd;
	int		status;

	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		return (perror("Open failed"), 0);
	if (malloc_matrix(argv1, lst) == 0)
		return (close(fd), 0);
	i = 0;
	status = 1;
	while (status > 0)
	{
		status = get_next_line(fd, &one_line, 2);
		if (status == -1)
			return (close(fd), free(one_line), 0);
		if (status == 0)
			return (close(fd), free(one_line), 1);
		if (!fill_in_matrix(lst->matrix[i++], one_line))
			return (free(one_line), array_free(lst->matrix, lst), close(fd), 0);
		free(one_line);
	}
	return (close(fd), 1);
}
