/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:00:00 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/18 17:00:11 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	list_init(t_list *lst)
{
	lst->matrix = NULL;
	lst->width = 0;
	lst->length = 0;
	lst->mlx = NULL;
	lst->window = NULL;
	lst->zoom = 30;
	lst->color = 0xffffff;
	lst->angle = 0.6;
	lst->image.img = NULL;
	lst->image.addr = NULL;
	lst->image.b_per_p = 0;
	lst->image.l_len = 0;
	lst->image.end = 0;
	lst->point1.x = 0;
	lst->point1.y = 0;
	lst->point1.z = 0;
	lst->point2.x = 0;
	lst->point2.y = 0;
	lst->point2.z = 0;
	lst->offset_x = 900;
	lst->offset_y = 300;
}

int	move_with_key(int the_key, t_list *lst)
{
	printf("%d\n", the_key);
	if (the_key == 65362)
		lst->offset_y += 10;
	if (the_key == 65364)
		lst->offset_y += 10;
	if (the_key == 65363)
		lst->offset_x += 10;
	if (the_key == 65361)
		lst->offset_x += 10;
	mlx_clear_window(lst->mlx, lst->window);
	draw_lines(lst, -1 , -1);
	return(0);
}

int	close_mlx(t_list *lst)
{
	printf("%p\n", lst->mlx);
	mlx_destroy_image(lst->mlx, lst->image.img);
	mlx_destroy_window(lst->mlx, lst->window);
	mlx_destroy_display(lst->mlx);
	free(lst->mlx);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_list	*input;

	if (argc != 2)
		return (ft_putstr_fd("Invalid input\n", 2), 0);
	input = (t_list *)malloc(sizeof(t_list));
	if (!input)
		return (0);
	list_init(input);
	read_from_file(argv[1], input);
	input->mlx = mlx_init();
	/* if (!input->mlx)
		return (free(input), 0) */;
	input->window = mlx_new_window(input->mlx, 1920, 1080, "FdF");
	input->image.img = mlx_new_image(input->mlx, 1920, 1080);
	input->image.addr = mlx_get_data_addr(input->image.img, &input->image.b_per_p, &input->image.l_len, &input->image.end);
	draw_lines(input, -1, -1);
	mlx_put_image_to_window(input->mlx, input->window, input->image.img, 0, 0);
	//mlx_key_hook(input->window, move_with_key, &input);
	mlx_hook(input->window, DestroyNotify, 0, close_mlx, input);
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
	} */
}