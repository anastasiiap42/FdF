/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apashkov <apashkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:00:00 by apashkov          #+#    #+#             */
/*   Updated: 2023/12/21 20:45:01 by apashkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	list_init(t_list *lst)
{
	lst->mlx = NULL;
	lst->window = NULL;
	lst->zoom = 30;
	lst->color = 0xffffff;
	lst->angle = 0.6;
	lst->height = 0;
	lst->length = 0;
	lst->image.img = NULL;
	lst->image.addr = NULL;
	lst->image.b_per_p = 0;
	lst->image.l_len = 0;
	lst->image.end = 0;
	lst->offset_x = 900;
	lst->offset_y = 300;
}

int	close_mlx(t_list *lst)
{
	mlx_destroy_image(lst->mlx, lst->image.img);
	mlx_destroy_window(lst->mlx, lst->window);
	mlx_destroy_display(lst->mlx);
	free(lst->mlx);
	array_free(lst->matrix, lst);
	exit(0);
}

int	key_handling(int the_key, t_list *lst)
{
	if (the_key == XK_Escape)
		close_mlx(lst);
	if (the_key == XK_plus)
		lst->zoom += 1;
	if (the_key == XK_minus)
		lst->zoom -= 1;
	if (the_key == XK_KP_Add)
		lst->height += 1;
	if (the_key == XK_KP_Subtract)
		lst->height -= 1;
	if (the_key == XK_Down)
		lst->offset_y += 10;
	if (the_key == XK_Up)
		lst->offset_y -= 10;
	if (the_key == XK_Right)
		lst->offset_x += 10;
	if (the_key == XK_Left)
		lst->offset_x -= 10;
	mlx_destroy_image(lst->mlx, lst->image.img);
	lst->image.img = mlx_new_image(lst->mlx, 1920, 1080);
	lst->image.addr = mlx_get_data_addr(lst->image.img,
			&lst->image.b_per_p, &lst->image.l_len, &lst->image.end);
	draw_lines(lst, -1, -1);
	mlx_put_image_to_window(lst->mlx, lst->window, lst->image.img, 0, 0);
	return (0);
}

int	mouse_handling(int the_key, int x, int y, t_list *lst)
{
	x = 1;
	y = 1;
	if (the_key == 4)
		lst->angle -= 0.1;
	if (the_key == 5)
		lst->angle += 0.1;
	if (the_key == 2)
		lst->angle = 0;
	mlx_destroy_image(lst->mlx, lst->image.img);
	lst->image.img = mlx_new_image(lst->mlx, 1920, 1080);
	lst->image.addr = mlx_get_data_addr(lst->image.img,
			&lst->image.b_per_p, &lst->image.l_len, &lst->image.end);
	draw_lines(lst, -1, -1);
	mlx_put_image_to_window(lst->mlx, lst->window, lst->image.img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	input;
	char	*one_line;

	one_line = NULL;
	if (argc != 2)
		return (ft_putstr_fd("Invalid input\n", 2), 0);
	list_init(&input);
	if (read_from_file(argv[1], &input, one_line) == 0)
		return (0);
	input.mlx = mlx_init();
	if (!input.mlx)
		return (0);
	input.window = mlx_new_window(input.mlx, 1920, 1080, "FdF");
	input.image.img = mlx_new_image(input.mlx, 1920, 1080);
	input.image.addr = mlx_get_data_addr(input.image.img,
			&input.image.b_per_p, &input.image.l_len, &input.image.end);
	draw_lines(&input, -1, -1);
	mlx_put_image_to_window(input.mlx, input.window, input.image.img, 0, 0);
	mlx_hook(input.window, DestroyNotify, 0, close_mlx, &input);
	mlx_hook(input.window, KeyPress, KeyPressMask, key_handling, &input);
	mlx_hook(input.window, ButtonPress, ButtonPressMask, mouse_handling,
		&input);
	mlx_loop(input.mlx);
}
	/*int i = 0;
	while (i < input.length)
	{
		int j = 0;
		while (j < input.width)
		printf("%d ", input.matrix[i][j++]);
		printf("\n");
		i++;
	} */