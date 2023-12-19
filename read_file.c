/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:30 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/19 12:09:37 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

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
	int		flag;

	flag = 0;
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		return (perror("Open failed"), free(lst), exit (1), 1);
	res = 0;
	while (errno != ENOMEM && errno != EROFS)
	{
		one_line = get_next_line(fd);
		if (!one_line)
			return (close(fd), res);
		if (flag == 0)
		{
			lst->width = which_width(one_line);
			flag = 1;
		}
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

int	read_from_file(char	*argv1, t_list *lst)
{
	int		i;
	char	*one_line;
	int		fd;

	one_line = "";
	lst->length = which_length(argv1, lst);
	lst->matrix = (int **)malloc(sizeof(int *) * (lst->length));
	if (!lst->matrix)
		return (0);
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		return (perror("Open failed"), free(lst->matrix), 0);
	i = 0;
	while (i < lst->length)
		lst->matrix[i++] = (int *)malloc(sizeof(int) * (lst->width));
	i = 0;
	while (errno != ENOMEM && errno != EROFS)
	{
		one_line = get_next_line(fd);
		if (!one_line)
			break ;
		if (!fill_in_matrix(lst->matrix[i++], one_line))
			return (free(one_line), array_free(lst->matrix, lst), close(fd), 0);
		free(one_line);
	}
	if (errno == ENOMEM || errno == EROFS)
		return (0);
	close(fd);
	return (1);
}
