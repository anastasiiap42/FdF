/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:41:30 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/12 19:55:49 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

int	which_width(char *one_line)
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

int	which_length(char *argv1, t_list *lst)
{
	int		res;
	char	*one_line;
	int		fd;
	int		flag;

	flag = 0;
	fd = open(argv1, O_RDONLY);
	res = 0;
	while (1)
	{
		one_line = get_next_line(fd);
		if (!one_line)
			break;
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

void	fill_in_matrix(int *matrix_line, char *line)
{
	char	**map_line;
	int		c;

	map_line = ft_split(line, ' ');
	if (!map_line)
		return ;
	c = -1;
	while (map_line[++c])
	{
		matrix_line[c] = ft_atoi(map_line[c]);
		free(map_line[c]);
	}
	free(map_line);
}

void	read_from_file(char	*argv1, t_list *lst)
{
	int		i;
	char	*one_line;
	int		fd;

	lst->length = which_length(argv1, lst);
	lst->matrix = (int **)malloc(sizeof(int *) * (lst->length + 1));
	fd = open(argv1, O_RDONLY);
	i = 0;
	while (i <= lst->length)
		lst->matrix[i++] = (int *)malloc(sizeof(int) * (lst->width + 1));
	i = 0;
	while ((one_line = get_next_line(fd)) && errno != ENOMEM && errno != EROFS)
	{
		//one_line = get_next_line(fd);
		fill_in_matrix(lst->matrix[i++], one_line);
		free(one_line);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_list	*input;

	if (argc != 2)
		return (perror("Invalid input"), 1);
	input = (t_list *)malloc(sizeof(t_list));
	if (!input)
		return (0);
	read_from_file(argv[1], input);
	printf("length: %d, width: %d\n", input->length, input->width);
	input->mlx = mlx_init();
	if (!input->mlx)
		return (perror("Mlx init failed"), 1);
	input->window = mlx_new_window(input->mlx, 1920, 1080, "FdF");
	if (!input->mlx)
		return (perror("Mlx new window failed"), 1);
	input->zoom = 30;
	input->image = mlx_new_image(input->mlx, 1920, 1080);
	if (!input->image)
		return (perror("Mlx new image failed"), 1);
	draw_lines(input);
	//algorithm(50, 60, 40, 70, input);
	mlx_loop(input->mlx);

	/* ----------------------- Printing part ----------------------------------------*/
	
	/* int i = 0;
	while (i < input->length)
	{
		int j = 0;
		while (j < input->width)
		printf("%d ", input->matrix[i][j++]);
		printf("\n");
		i++;
	}
	 */
	/* ------------------------------------------------------------------------------*/
	
}
