/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:30 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:27:49 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_in_matrix(int *matrix_line, char *line)
{
	char	**map_line;
	int		rows;

	map_line = ft_split(line, ' ');
	if (!map_line)
		return (NULL);
	rows = 0;
	while (map_line[rows])
	{
		matrix_line[rows] = ft_atoi(map_line[rows++]);
		free(map_line[rows]);
	}
	free(map_line);
}

void	*read_from_file(int fd, data **lst)
{
	char	*l;
	
	while (l)
	{
		l = get_next_line(fd);
		if (!l)
			return (NULL);
		fill_in_matrix();
		free(l);
	}
}

int	main(char *argv[], int argc)
{
	int	file;
	data	*input;

	if (argc != 2)
		return (perror("Invalid input"));
	input = (data *)malloc(sizeof(data));
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (perror("Open failed"));
	read_from_file(file, input);
}