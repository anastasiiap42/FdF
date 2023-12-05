/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:30 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/05 19:18:07 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	which_length(int fd)
{
	int		res;
	char	*one_line;

	res = 1;
	one_line = get_next_line(fd);
	if (!one_line || !one_line[0])
		return (-1);
	while (one_line)
	{
		one_line = get_next_line(fd);
		res++;
		free(one_line);
	}
	return (res);
}

int	which_width(int fd)
{
	int		res;
	char	*one_line;
	int		i;

	res = 0;
	one_line = get_next_line(fd);
	if (!one_line)
			return (-1);
	i = -1;
	while (one_line[++i])
	{
		if (one_line[i] == ' '
			&& (one_line[i + 1] != ' ' || one_line[i + 1] != '\0'))
			res++;
	}
	free(one_line);
	return (res);
}

void	fill_in_matrix(int *matrix_line, char *line)
{
	char	**map_line;
	int		rows;

	map_line = ft_split(line, ' ');
	if (!map_line)
		return ;
	rows = 0;
	while (map_line[rows])
	{
		matrix_line[rows] = ft_atoi(map_line[rows]);
		free(map_line[rows]);
		rows++;
	}
	free(map_line);
}

void	read_from_file(int fd, t_list *lst)
{
	int		i;
	char	*one_line;

	lst->width = which_width(fd);
	lst->length = which_length(fd);
	lst->matrix = (int **)malloc(sizeof(int *) * (lst->length + 1));
	i = 0;
	while (i <= lst->length)
		lst->matrix[i++] = (int *)malloc(sizeof(int) * (lst->width + 1));
	i = 0;
	while ((one_line = get_next_line(fd)))
	{
		printf("%s\n", one_line);
		fill_in_matrix(lst->matrix[i++], one_line);
		free(one_line);
	}
	lst->matrix[i] = NULL;
}

int	main(int argc, char *argv[])
{
	int		file;
	t_list	*input;

	if (argc != 2)
		return (perror("Invalid input"), 0);
	input = (t_list *)malloc(sizeof(t_list));
	if (!input)
		return (0);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (perror("Open failed"), free(input), 0);
	read_from_file(file, input);

	/* ----------------------- Printing part ----------------------------------------*/
	
	int i = 0;
	while (i < input->length)
	{
		int j = 0;
		printf("hii\n");
		printf("%d\n", input->matrix[i][j]);
		/* while (j < input->width)
			printf("%d ", input->matrix[i][j++]); */
		printf("\n");
		i++;
	}
}
